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
ll k,m,n,t_case;
int main(){
	scanf("%lld",&t_case);
	while(t_case--){
		scanf("%lld%lld%lld",&n,&m,&k);
		puts((n-1)+(m-1)*n==k?"YES":"NO");
	}
	return 0;
}