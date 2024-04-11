//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
#define mp make_pair
#define pb push_back
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define be begin()
#define en end()
#define sqr(x) ((x)*(x))
#define ret return puts("-1"),0;
#define put putchar('\n')
#define inf 1000000005
#define mod 998244353
#define int ll
//#define N
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,X,Y,a,b,ans,x,t,y;
signed main()
{
	T=read();
	while (T--)
	{
		X=read(),Y=read();
		if (X>Y) swap(X,Y);
		a=read(),b=read();
		if (a>b) swap(a,b);
		if (a==b) writeln(X/a);
		else
		{
			ans=0;
			x=min(X/a,Y/b);
			x=min((Y-X)/(b-a),x);
			X-=x*a,Y-=x*b;
			y=min(X/(a+b),Y/(a+b));
			X-=y*(a+b);
			Y-=y*(a+b);
			t=0;
			if (X>=a&&Y>=b) t++;
			ans=max(ans,y*2+x+t);
			X+=x*a,Y+=x*b;
			X+=y*(a+b);
			Y+=y*(a+b);
			
			x=min(X/a,Y/b);
			x=min((Y-X)/(b-a)+1,x);
			X-=x*a,Y-=x*b;
			y=min(X/(a+b),Y/(a+b));
			X-=y*(a+b);
			Y-=y*(a+b);
			t=0;
			if (X>=a&&Y>=b) t++;
//			cout<<x<<" "<<y<<" "<<t<<" "<<X<<" "<<Y<<endl;
			ans=max(ans,y*2+x+t);
			X+=x*a,Y+=x*b;
			X+=y*(a+b);
			Y+=y*(a+b);
			writeln(ans);
		}
	}
			
			
			
}
/*

*/