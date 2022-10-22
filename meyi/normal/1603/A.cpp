#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		ll l=1;
		bool flag=false;
		for(ri i=1;i<=n;++i){
			if(l<=(int)1e9)l=l*(i+1)/__gcd(l,(ll)(i+1));
			scanf("%d",a+i);
			if(a[i]%l==0)flag=true;
		}
		puts(flag?"NO":"YES");
		
	}
	return 0;
}