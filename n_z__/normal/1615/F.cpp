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
                                                                    #define debug true
#if debug==false
#define cin Fastio :: cin
#define cout Fastio :: cout
#define endl Fastio :: endl
#endif
using namespace std;
                                                                    #define use_pbds false
#if use_pbds==true
#include<bits/extc++.h>
using namespace __gnu_pbds;
#endif
#define int long long
                                                                    #define multiple_test_data true
int max(int a,signed b){return max(a,(int)b);}
int min(int a,signed b){return min(a,(int)b);}
int max(signed b,int a){return max(a,(int)b);}
int min(signed b,int a){return min(a,(int)b);}
const int p=1e9+7;
int qp(int x,int n=p-2)
{
    int r=1;
    while(n)
    {
        if(n&1)r=r*x%p;
        x=x*x%p,n>>=1;
    }
    return r;
}
int fac[1000001],ifac[1000001];
void init(int n)
{
    fac[0]=1;
    for(int x=1;x<=n;x++)
    fac[x]=fac[x-1]*x%p;
    ifac[n]=qp(fac[n]);
    for(int x=n;x>=1;x--)
    ifac[x-1]=ifac[x]*x%p;
}
int C(int x,int y)
{
    if(x>y)swap(x,y);
    return fac[y]*ifac[x]%p*ifac[y-x]%p;
}
void Init_for_all_task()
{
//111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111//
//111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111//
}
/*main-head---------------------------------------------------------------------------------------*/
//222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222//
int f[2001][4001],g[2001][4001];
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
    int n;
    string s,t;
    cin>>n>>s>>t;
    for(int x=1;x<n;x+=2)
    s[x]^=1,t[x]^=1;
	s=" "+s,t=" "+t;
	f[0][n]=1;
	for(int a=1;a<=n;a++)
	for(int b=n-a;b<=n+a;b++)
	for(int x=0;x<=1;x++)
	for(int y=0;y<=1;y++)
	if((x^1)!=s[a]-'0'&&(y^1)!=t[a]-'0')
    f[a][b+x-y]=(f[a][b+x-y]+f[a-1][b])%p,g[a][b+x-y]=((g[a][b+x-y]+g[a-1][b])%p+abs(b-n)*f[a-1][b]%p)%p;
    cout<<g[n][n]<<endl;
    for(int x=0;x<=n;x++)
    for(int y=0;y<=2*n;y++)
    f[x][y]=g[x][y]=0;
//444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444//
/*Main-end----------------------------------------------------------------------------------------*/
}
/*Main-end----------------------------------------------------------------------------------------*/
}
/*namespace-end-----------------------------------------------------------------------------------*/
main()
{
    Init_for_all_task();
#if multiple_test_data==true
    int t;cin>>t;while(t--)
#endif
    nz::Main();
}
/*main-end----------------------------------------------------------------------------------------*/