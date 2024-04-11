#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define SZ(k) k.size()
#define ALL(k) k.begin(),k.end()
#define DEBUG(k...) fprintf(stderr,k)
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
template<class T>inline bool chkmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chkmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int b[maxn],bel[maxn],k,m,n,t_case;
struct val{
	int a,id;
	inline bool operator<(const val &k)const{
		return a<k.a;
	}
}a[maxn];
struct node{
	int id;
	inline bool operator<(const node &k)const{
		return b[id]>b[k.id];
	}
};
priority_queue<node>q;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%d",&n,&m,&k);
		for(ri i=1;i<=m;++i)b[i]=bel[i]=0;
		for(ri i=1;i<=n;++i)scanf("%d",&a[i].a),a[i].id=i;
		sort(a+1,a+n+1);
		while(q.size())q.pop();
		for(ri i=1,j=n;i<=m;++i,--j)b[i]=a[j].a,q.push({i}),bel[a[j].id]=i;
		for(ri i=n-m;i;--i){
			ri now=q.top().id;q.pop();
			b[now]+=a[i].a;q.push({now});
			bel[a[i].id]=now;
		}
		ri mx=INT_MIN,mn=INT_MAX;
		for(ri i=1;i<=m;++i)mx=max(mx,b[i]),mn=min(mn,b[i]);
		if(mx-mn<=k){
			puts("YES");
			for(ri i=1;i<=n;++i)printf("%d ",bel[i]);
			puts("");
		}
		else puts("NO");
	}
	return 0;
}