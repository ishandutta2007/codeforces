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

#define N 1005
//#define M 300005

int n,p;
char s[N];

void work(int i){
	if(i>n) return;
	s[i]='a'-1;
	if(s[i]+1<=p && s[i-1]!=s[i]+1 && (i==1 || s[i-2]!=s[i]+1)){
		s[i]=s[i]+1;
		work(i+1);
		return;
	}
	if(s[i]+2<=p && s[i-1]!=s[i]+2 && (i==1 || s[i-2]!=s[i]+2)){
		s[i]=s[i]+2;
		work(i+1);
		return;
	}
	if(s[i]+3<=p && s[i-1]!=s[i]+3 && (i==1 || s[i-2]!=s[i]+3)){
		s[i]=s[i]+3;
		work(i+1);
		return;
	}
}

void check(){
	rep(i,2,n) if(s[i]==s[i-1] || s[i]==s[i-2]) return;
	puts(s+1);
	exit(0);
}

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);

	scanf("%d%d",&n,&p); p+='a';
	p--;
	scanf("%s",s+1);
	dep(i,n,1){
		if(s[i]+1<=p && s[i-1]!=s[i]+1 && (i==1 || s[i-2]!=s[i]+1)){
			s[i]=s[i]+1;
			work(i+1);
			check();
		}
		if(s[i]+2<=p && s[i-1]!=s[i]+2 && (i==1 || s[i-2]!=s[i]+2)){
			s[i]=s[i]+2;
			work(i+1);
			check();
		}
		if(s[i]+3<=p && s[i-1]!=s[i]+3 && (i==1 || s[i-2]!=s[i]+3)){
			s[i]=s[i]+3;
			work(i+1);
			check();
		}
	}
	puts("NO");
}