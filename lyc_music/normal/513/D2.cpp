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
//#define int ll
#define N 1000005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
//#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int siz[N],L[N],R[N];
int n,q;
int a[N],b[N],c[N];
int ans[N][2];
void dfs(int k,int lim)
{
//	if (k>lim) return;
	siz[k]=max(siz[k],lim);
	if (k==siz[k]) return;
//	cout<<k<<" "<<siz[k]<<" "<<lim<<" "<<L[k]<<" "<<R[k]<<endl;
	if (L[k]>=k+1) 
	{
//		cout<<"!"<<k<<endl;
		
		ans[k][0]=k+1;
		dfs(k+1,L[k]);
		if (siz[k+1]>R[k]) 
		{
//			cout<<"!"<<k<<" "<<R[k]<<" "<<siz[k+1]<<endl;
			cout<<"IMPOSSIBLE"<<endl;
			exit(0);
		}
		siz[k]=max(siz[k],siz[k+1]);
//		cout<<"?"<<k<<" "<<siz[k]<<endl;
		if (siz[k+1]+1<=siz[k])
		{
			ans[k][1]=siz[k+1]+1;
			dfs(siz[k+1]+1,siz[k]);
			siz[k]=max(siz[k],siz[siz[k+1]+1]);
		}
	}
	else
	{
		ans[k][1]=k+1;
		dfs(k+1,siz[k]);
		siz[k]=max(siz[k+1],siz[k]);
	}
}
void work(int k)
{
	if (!k) return;
	work(ans[k][0]);
	cout<<k<<" ";
	work(ans[k][1]);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for (int i=1;i<=n;i++) L[i]=siz[i]=i,R[i]=n;
	for (int i=1;i<=q;i++)
	{
	    string st;
		cin>>a[i]>>b[i]>>st;
		if (a[i]>=b[i]) return cout<<"IMPOSSIBLE",0;
		if (st=="LEFT") L[a[i]]=max(L[a[i]],b[i]);
		else
		R[a[i]]=min(R[a[i]],b[i]-1);
		siz[a[i]]=max(siz[a[i]],b[i]);
	}
	dfs(1,n);
	work(1);
}
/*

*/