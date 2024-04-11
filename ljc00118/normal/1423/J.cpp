#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#define NDEBUG
#endif
#include<bits/stdc++.h>
#define int long long
#define LL long long
#define MP make_pair
#define PB push_back
#define fi first
#define se second
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef pair<int,int>PII;typedef vector<int>VI;typedef vector<PII>VII;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int P=1e9+7;
int T;

int sol(int n){
	if(n<=2)return n;
	int num=(n+1)/4%P;
	int sum=(num*(num+1)/2%P+P-1)%P;
	int tmp=0;
	if((n-3)%4>=1)tmp+=num+1;
	if((n-3)%4>=3)tmp+=num+1;
	return (2+sum*2+tmp)%P;
}
signed main(){
	rd(T);
#ifdef xay5421
	rep(i,1,T){
		int n=i;
#else
	while(T--){
		int n;rd(n);
#endif
		pt(sol(n),'\n');
	}
	return 0;
}