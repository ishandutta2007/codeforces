#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#if ONLINE_JUDGE==luogu
#pragma GCC optimize(3)
#endif
#include<bits/stdc++.h>
namespace Fread{
const int SIZE= 1 << 16;
	char buf[SIZE],*S,*T;
	inline char getchar(){if(S==T){T=(S=buf)+
	fread(buf,1,SIZE,stdin);if(S==T)return'\n';}return *S++;}
}
namespace Fwrite {
const int SIZE= 1 << 16;
	char buf[SIZE],*S=buf,*T=buf+SIZE;
	inline void flush(){fwrite(buf,1,S-buf,stdout);S=buf;}
	inline void putchar(char c){*S++=c;if(S==T)flush();}
	struct NTR{~NTR(){flush();}}ztr;
}
#ifdef ONLINE_JUDGE
	#define getchar Fread::getchar
	#define putchar Fwrite::putchar
#endif
namespace Fastio{
struct Reader{
	template<typename T>Reader&operator>>(T&x){
		char c=getchar();short f=1;
		while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}
		x=0;while(c>='0'&&c<='9'){
			x=(x<<1)+(x<<3)+(c^48);
			c=getchar();
		}x*=f;return *this;
	}
	Reader&operator>>(double&x){
		char c=getchar();short f=1,s=0;x=0;double t=0;
		while((c<'0'||c>'9')&&c!='-'&&c!='.'){if(c=='-')f*=-1;c=getchar();}
		while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();
		if(c=='.')c=getchar();else return x*=f,*this;
		while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();
		while(s--)t/=10.0;x=(x+t)*f;return*this;
	}
	Reader&operator>>(long double&x){
		char c=getchar();short f=1,s=0;x=0;long double t=0;
		while((c<'0'||c>'9')&&c!='-'&&c!='.'){if(c=='-')f*=-1;c=getchar();}
		while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();
		if(c=='.')c=getchar();else return x*=f,*this;
		while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();
		while(s--)t/=10.0;x=(x+t)*f;return*this;
	}
	Reader&operator>>(__float128&x){
		char c=getchar();short f=1,s=0;x=0;__float128 t=0;
		while((c<'0'||c>'9')&&c!='-'&&c!='.'){if(c=='-')f*=-1;c=getchar();}
		while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();
		if(c=='.')c=getchar();else return x*=f,*this;
		while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();
		while(s--)t/=10.0;x=(x+t)*f;return*this;
	}
	Reader&operator>>(char&c){
		c=getchar();while(c=='\n'||c==' '||c=='\r')c=getchar();
		return *this;
	}
	Reader&operator>>(char*str){
		int len=0;char c=getchar();
		while(c=='\n'||c==' '||c=='\r')c=getchar();
		while(c!='\n'&&c!=' '&&c!='\r')str[len++]=c,c=getchar();
		str[len]='\0';return*this;
	}
	Reader&operator>>(std::string&str){
		int len=0;char c=getchar();
		while(c=='\n'||c==' '||c=='\r')c=getchar();
		while(c!='\n'&&c!=' '&&c!='\r')str.push_back(c),c=getchar();
		return*this;
	}
	Reader(){}
}cin;
const char endl='\n';
struct Writer{
const int Setprecision=6;
typedef __int128 mxdouble;
	template<typename T>Writer&operator<<(T x){
		if(x==0)return putchar('0'),*this;
		if(x<0)putchar('-'),x=-x;
		static int sta[45];int top=0;
		while(x)sta[++top]=x%10,x/=10;
		while(top)putchar(sta[top]+'0'),--top;
		return*this;
	}
	Writer&operator<<(double x){
		if(x<0)putchar('-'),x=-x;
		mxdouble _=x;x-=(double)_;static int sta[45];int top=0;
		while(_)sta[++top]=_%10,_/=10;if(!top)putchar('0');
		while(top)putchar(sta[top]+'0'),--top;putchar('.');
		for(int i=0;i<Setprecision;i++)x*=10;
		_=x;while(_)sta[++top]=_%10,_/=10;
		for(int i=0;i<Setprecision-top;i++)putchar('0');
		while(top)putchar(sta[top]+'0'),--top;
		return*this;
	}
	Writer&operator<<(long double x){
		if(x<0)putchar('-'),x=-x;
		mxdouble _=x;x-=(long double)_;static int sta[45];int top=0;
		while(_)sta[++top]=_%10,_/=10;if(!top)putchar('0');
		while(top)putchar(sta[top]+'0'),--top;putchar('.');
		for(int i=0;i<Setprecision;i++)x*=10;
		_=x;while(_)sta[++top]=_%10,_/=10;
		for(int i=0;i<Setprecision-top;i++)putchar('0');
		while(top)putchar(sta[top]+'0'),--top;
		return*this;
	}
	Writer&operator<<(__float128 x){
		if(x<0)putchar('-'),x=-x;
		mxdouble _=x;x-=(__float128)_;static int sta[45];int top=0;
		while(_)sta[++top]=_%10,_/=10;if(!top)putchar('0');
		while(top)putchar(sta[top]+'0'),--top;putchar('.');
		for(int i=0;i<Setprecision;i++)x*=10;
		_=x;while(_)sta[++top]=_%10,_/=10;
		for(int i=0;i<Setprecision-top;i++)putchar('0');
		while(top)putchar(sta[top]+'0'),--top;
		return*this;
	}
	Writer&operator<<(char c){putchar(c);return*this;}
	Writer& operator<<(char*str){
		int cur=0;while(str[cur])putchar(str[cur++]);
		return *this;
	}
	Writer&operator<<(const char*str){
		int cur=0;while(str[cur])putchar(str[cur++]);
		return*this;
	}
	Writer&operator<<(std::string str){
		int st=0,ed=str.size();
		while(st<ed)putchar(str[st++]);
		return*this;
	}
	Writer(){}
}cout;
}
                                                                    #define need_C_or_qp       1
                                                                    #define off_fastio         0
                                                                    #define use_pbds           0
                                                                    #define multiple_test_data 0
                                                                    #define need_long_long     1
                                                                    const int N=               200000;
                                                                    const int p=               1e9+7;
#if off_fastio==0
#define cin Fastio :: cin
#define cout Fastio :: cout
#define endl Fastio :: endl
#endif
using namespace std;
#if use_pbds==1
#if ONLINE_JUDGE==luogu
#include<bits/extc++.h>
#else
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#endif
using namespace __gnu_pbds;
#endif
#if need_long_long==1
#define int long long
int max(int a,signed b){return max(a,(int)b);}
int min(int a,signed b){return min(a,(int)b);}
int max(signed b,int a){return max(a,(int)b);}
int min(signed b,int a){return min(a,(int)b);}
#endif
#if need_C_or_qp==1
int qp(int x,int n=p-2){int r=1;while(n){if(n&1)r=r*x%p;x=x*x%p,n>>=1;}return r;}
int fac[N+1],ifac[N+1];
void init(int n){fac[0]=1;for(int x=1;x<=n;x++)fac[x]=fac[x-1]*x%p;ifac[n]=qp(fac[n]);for(int x=n;x>=1;x--)ifac[x-1]=ifac[x]*x%p;}
int C(int x,int y){if(x<y||y<0)return 0;return fac[x]*ifac[y]%p*ifac[x-y]%p;}
#endif
void Init_for_all_task()
{
//111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111//
//111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111//
}
/*main-head---------------------------------------------------------------------------------------*/
//222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222//
int s1[N],s2[N];
mt19937 mt(time(0)),mtt(mt());
//222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222//
/*default-var-------------------------------------------------------------------------------------*/
namespace nz{
/*namespace-head----------------------------------------------------------------------------------*/
//333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333//
//333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333//
/*var-and-func------------------------------------------------------------------------------------*/
void Main(){
/*Main-head---------------------------------------------------------------------------------------*/
//444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444//
    int n,q;
    cin>>n>>q;
    int r=mtt()%p;
    for(int x=1;x<=n;x++)
    {
        int y;
        cin>>y;
        y+=r;
        y%=p;
        s1[x]=(s1[x-1]+y)%p;
        s2[x]=(s2[x-1]+y*y%p)%p;
    }
	while(q--){
		int l,r,d;
		cin>>l>>r>>d;
		if(((s2[r]-s2[l-1])%p+p)%p==((r-l+1)*(((s1[r]-s1[l-1]-(r-l+1)*(r-l)/2%p*d%p)%p+p)%p)%p*qp(r-l+1)%p*(((s1[r]-s1[l-1]-(r-l+1)*(r-l)/2%p*d%p)%p+p)%p)%p*qp(r-l+1)%p+(r-l+1)*(r-l)%p*d%p*(((s1[r]-s1[l-1]-(r-l+1)*(r-l)/2%p*d%p)%p+p)%p)%p*qp(r-l+1)%p+(r-l+1)*(r-l)*((r-l+1)*2-1)/6%p*d%p*d%p)%p) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
//444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444//
/*Main-end----------------------------------------------------------------------------------------*/
}
/*Main-end----------------------------------------------------------------------------------------*/
}
/*namespace-end-----------------------------------------------------------------------------------*/
main()
{
    Init_for_all_task();
#if multiple_test_data==1
    int t;cin>>t;while(t--)
#endif
    nz::Main();
}
/*main-end----------------------------------------------------------------------------------------*/