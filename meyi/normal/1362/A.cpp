#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
ll a,b;
int t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%lld%lld",&a,&b);
		if(a==b)puts("0");
		else{
			if(a<b)swap(a,b);
			if(a%b)puts("-1");
			else{
				a/=b;
				ri cnt=0;
				while(a%2==0)a>>=1,++cnt;
				if(a!=1)puts("-1");
				else printf("%d\n",cnt/3+bool(cnt%3));
			}
		}
	}
	return 0;
}