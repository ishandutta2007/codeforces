#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
using namespace std;
typedef pair<int,int> pr;
#define mkp make_pair
const int MAXN=2e5+5;
int n,q,a[MAXN];
set<int> st;
vector<pr> mdf[MAXN],qry[MAXN];
int mi[MAXN];
int ans[MAXN];
inline void Add(int x,int y){
	//printf("x %d y %d\n",x,y);
	for(int i=x; i; i&=i-1)
		mi[i]=min(mi[i],y);
}
inline int Query(int x){
	int res=mi[x];
	for(int i=x; i<=n; i+=i&-i)
		res=min(res,mi[i]);
	return res;
}
int main(){
	//freopen("in1.txt","r",stdin);
	scanf("%d%d",&n,&q);
	for(int i=0; i<=n+1; i++)
		st.insert(i);
	for(int i=1; i<=q; i++){
		int t,l,r,x;
		scanf("%d",&t);
		if(t==0){
			scanf("%d%d%d",&l,&r,&x);
			if(x==0){
				while(1){
					auto it=st.lower_bound(l);
					if(it==st.end()||*it>r) break;
					st.erase(it);
				}
			}else mdf[r].push_back(mkp(l,i));
			ans[i]=-2;
		}else{
			scanf("%d",&x);
			if(st.find(x)!=st.end()){
				auto it=st.upper_bound(x);
				int r=*it-1;
				it--;
				it--;
				int l=*it+1;
				qry[r].push_back(mkp(l,i));
				//printf("l %d r %d\n",l,r);
			}else ans[i]=0;
		}
	}
	memset(mi,0x3f,sizeof(mi));
	for(int i=1; i<=n; i++){
		for(pr j:mdf[i])
			Add(j.first,j.second);
		for(pr j:qry[i]){
			int t=Query(j.first);
			if(t<j.second) ans[j.second]=1;
			else ans[j.second]=-1;
			//printf("t %d\n",t);
		}
	}
	for(int i=1; i<=q; i++)
		if(ans[i]>-2){
			if(ans[i]==1) puts("YES");
			else if(ans[i]==-1) puts("N/A");
			else puts("NO");
		}
	return 0;
}