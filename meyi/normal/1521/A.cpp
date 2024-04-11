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
int t_case;
ll m,n;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%lld%lld",&n,&m);
		if(m==1)puts("NO");
		else if(m==2)printf("YES\n%lld %lld %lld\n",n,n*3,n*4);
		else printf("YES\n%lld %lld %lld\n",n,n*(m-1),n*m);
	}
	return 0;
}