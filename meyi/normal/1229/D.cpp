#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int a[maxn],cnt,ele[123],k,n,pre[123],to[123][123],tot;
ll ans,sum;
map<vector<int>,int>id;
vector<int>cur,p[123];
bool vis[maxn];
inline void insert(int x){
	if(vis[x])return;
	queue<int>q;
	cur.push_back(x),q.push(x),++sum,vis[x]=true;
	while(q.size()){
		ri now=q.front();q.pop();
		vector<int>tmp;
		for(ri i:cur)
			if(!vis[to[now][i]])
				tmp.push_back(to[now][i]),q.push(to[now][i]),++sum,vis[to[now][i]]=true;
		if(sum==cnt)break;
		cur.insert(cur.end(),tmp.begin(),tmp.end());
	}
}
int main(){
	scanf("%d%d",&n,&k);
	vector<int>b(k);
	iota(b.begin(),b.end(),1);
	do p[++cnt]=b,id[b]=cnt;while(next_permutation(b.begin(),b.end()));
	for(ri i=1;i<=n;++i){
		for(ri &j:b)scanf("%d",&j);
		a[i]=id[b];
	}
	for(ri i=1;i<=cnt;++i)
		for(ri j=1;j<=cnt;++j){
			for(ri l=0;l<k;++l)b[l]=p[i][p[j][l]-1];
			to[i][j]=id[b];
		}
	for(ri i=1;i<=n;++i){
		if(!pre[a[i]])ele[++tot]=a[i];
		pre[a[i]]=i;
		sort(ele+1,ele+tot+1,[&](int x,int y){return pre[x]>pre[y];});
		cur.clear(),sum=0,clear(vis,cnt);
		for(ri j=1;j<=tot;++j){
			insert(ele[j]);
			ans+=sum*(pre[ele[j]]-pre[ele[j+1]]);
		}
	}
	printf("%lld",ans);
	return 0;
}