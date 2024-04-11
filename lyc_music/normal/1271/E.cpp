//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
#define IOS ios::sync_with_stdio(false)
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
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,a[105],f[105],vis[105];
set<int>S;
int work(int k,int lim)
{
	if (k<0) return 0;
//	cout<<k<<" "<<lim<<endl;
	if (vis[k]&&!lim) return f[k];
	if (!lim) 
	{
		vis[k]=1;
	}
	if (k==0&&lim) return a[k]+1;
	if (k==0) return 2;
	if (lim==1)
	{
		int res=work(k-1,1);
		if (a[k]) res+=work(k-1,0);
		return res;
	}
	f[k]=work(k-1,0)+2;
	return f[k];
}
signed main()
{
	n=read();m=read();
	for (int i=0;i<64;i++)
		a[i]=(n>>i)%2;	
//	writeln(work(1,0));
	for (int i=0;i<64;i++)
	{
		int s=(1ll<<(i))-1;
		if (!a[i]) s+=(1ll<<(i))-1;
		s+=n-((n>>i)<<i)+1;
//		cout<<i<<"."<<s<<endl;
		int now=n>>i;
//		if (i==56) cout<<i<<" "<<s<<" "<<(n>>i)<<endl;
		if (s>=m)
		{
//			now*=2,
//			cout<<s<<"!!!"<<endl;
			S.insert((n>>i));
//			return 0;
		}
		if (!a[i]) continue;
		s=(1ll<<(i))-1;
		if (a[i]) s+=n-((n>>i)<<i)+1;
//		if (i==1) cout<<s<<endl;
		s+=((1ll<<i)-1)*2+1;
		int pp=(n>>(i+1))<<1;
		if (s>=m)
		{
//			cout<<"!"<<i<<" "<<" "<<s<<endl;
			for (int now=i-1;now>=0;now--)
			{
//				cout<<pp<<" "<<now<<" "<<((1ll<<(now))-1)*2<<endl;
				if (((1ll<<(now))-1)*2>=m) pp*=2,pp+=1;
				else
					if (((1ll<<(now+1))-1)*2>=m) pp*=2;
					else break;
			}
			S.insert(pp);
//			return 0;
		}	
	}
	writeln(*S.rbegin());
}
/*

*/