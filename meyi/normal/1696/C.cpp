#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],b[maxn],k,m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		typedef pair<ll,ll> pii;
		#define fi first
		#define se second
		vector<pii>x,y;
		auto insert=[&](vector<pii>&v,int k,int num){
			if(v.empty()||v.back().fi!=k)v.emplace_back(k,num);
			else v.back().se+=num;
		};
		for(ri i=1;i<=n;++i){
			scanf("%d",a+i);
			ri tmp=1;
			while(a[i]%m==0)a[i]/=m,tmp*=m;
			insert(x,a[i],tmp);
		}
		scanf("%d",&k);
		for(ri i=1;i<=k;++i){
			scanf("%d",b+i);
			ri tmp=1;
			while(b[i]%m==0)b[i]/=m,tmp*=m;
			insert(y,b[i],tmp);
		}
		puts(x!=y?"NO":"YES");
	}
	return 0;
}