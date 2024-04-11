#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
#include<cstdlib>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
#define LL long long
#define LB long double
#define mod 1000000007
#define hash1 100000007
#define hash2 1000000007
#define inf 0x7f7f7f7f
#define infl 0x7f7f7f7f7f7f7f7fll
using namespace std;
inline int lowbit(int x){return x&-x;}
inline int ABS(int x){return x<0?-x:x;}
inline LL ABS(LL x){return x<0?-x:x;}
inline void MAX(int &a,int b){if(b>a)a=b;}
inline void MAX(LL &a,LL b){if(b>a)a=b;}
inline void MIN(int &a,int b){if(b<a)a=b;}
inline void MIN(LL &a,LL b){if(b<a)a=b;}
int fast(int x,int v){int ans=1;for(;v;v>>=1,x=(LL)x*x%mod)if(v&1)ans=(LL)ans*x%mod;return ans;}
LL fast(LL x,LL v){LL ans=1;for(;v;v>>=1,x=x*x%mod)if(v&1)ans=ans*x%mod;return ans;}
inline LL sqr(int x){return x*x;}

int n,s;

int main(){
//	freopen("2.in","r",stdin);
//	freopen("2.out","w",stdout);
	
	scanf("%d",&n);
	if(n<4){
		puts("NO");
		return 0;
	}
	puts("YES");
	s=0;
	if(n&1){
		puts("2 - 1 = 1");
		puts("1 + 3 = 4");
		puts("4 * 5 = 20");
		puts("20 + 4 = 24");
		s=6;
	}else{
		puts("1 * 2 = 2");
		puts("2 * 3 = 6");
		puts("6 * 4 = 24");
		s=5;
	}
	for(int i=s;i<=n-1;i+=2){
		printf("%d - %d = 1\n",i+1,i);
		printf("1 * 24 = 24\n");
	}
}