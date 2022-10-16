#include<bits/stdc++.h>
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
	Reader(){}
}cin;
const char endl='\n';
struct Writer{
const int Setprecision=6;
typedef int mxdouble;
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
	Writer(){}
}cout;
}
#define cin Fastio :: cin
#define cout Fastio :: cout
#define endl Fastio :: endl
#define string char*
using namespace std;
#define int long long
vector<int>v[1000001];
int fa[1000001];
pair<int,int>deep[1000001];
int del[1000001];
int ans=0;
void dfs(int now,int gf)
{
	for(auto q:v[now])
	if(q!=gf){
		deep[q].first=deep[now].first+1;
		fa[q]=now;
		dfs(q,now);
	}
}
void dfs2(int now,int jl)
{
	del[now]=jl;
	if(jl==1)return;
	/*if(jl==3){
		for(auto q:v[now])
		dfs2(q,jl-1);
		return;
	}*/
	for(auto q:v[now])
	if(del[q]<jl-1)dfs2(q,jl-1);
}
main()
{
	/*freopen("tbcs.in","r",stdin);
	freopen("tbcs.out","w",stdout);*/
	int n;
	cin>>n;
	for(int x=1;x<n;x++)
	{
		deep[x].second=x;
		int y,z;
		cin>>y>>z;
		v[y].push_back(z);
		v[z].push_back(y);
	}
	deep[n].second=n;
	deep[1].first=0,fa[1]=0;
	dfs(1,0);
	sort(deep+1,deep+1+n,greater<pair<int,int> >());
	int now=1;
	while(1){
		while(del[deep[now].second]&&now<=n)
		now++;
		if(now>n)break;
		if(deep[now].first<=2)break;
		ans++;
		dfs2(fa[deep[now].second],2);
		/*for(int x=1;x<=n;x++)
		cerr<<del[x];cerr<<endl;*/
	}
	cout<<ans<<endl;
}