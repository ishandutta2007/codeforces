//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define foor(i,a,b) for (int i=(a);i<=(b);i++)
#define door(i,a,b) for (int i=(a);i>=(b);i--)
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
#define mod 1000000007
#define int ll
#define N 1000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int f[N],pow2[N],T,n,m;
int now;
int bas=998244353;
int ans1;
string st,ans,st1;
map<int,int>Mp;
int work()
{
	for (int i=ans.length()-1;i>=1;i--)
		if (ans[i]=='0')
		{
			ans[i]='1';
			now=(now+pow2[ans.length()-i-1]+mod)%mod;
//			cout<<i<<"!"<<now<<endl;
			return 1;
		} else
		{
			ans[i]='0';
			now=(now-pow2[ans.length()-i-1]+mod)%mod;
//			cout<<i<<"?"<<now<<endl;
		}
	return 0;
}	
int query(int x,int y)
{
	return (f[y]-f[x-1]*pow2[y-x+1]%mod+mod)%mod;
}
signed main()
{
	pow2[0]=1;
	for (int i=1;i<=1000000;i++) pow2[i]=pow2[i-1]*bas%mod;
	IOS;
	cin>>T;
	while (T--)
	{
		Mp.clear();
		cin>>n>>m;
		cin>>st;
		ans1=0;
		st=' '+st;
		st1=st;
		for (int i=1;i<=n;i++)
		{
			if (st[i]=='0') st[i]='1';
			else st[i]='0';
			f[i]=(f[i-1]*bas+(st[i]-'0'+1))%mod;
		}
//		cout<<st<<endl;
		for (int i=1;i+m-1<=n;i++)
		{
			Mp[query(i,i+m-1)]++;
//			cout<<i<<" "<<i+m-1<<" "<<query(i,i+m-1)<<endl;
		}
		ans=" ";now=0;
		for (int i=1;i<=m;i++) ans+='0',now=now*bas+1,now%=mod;
		do
		{
//			cout<<now<<endl;
//			cout<<ans<<endl;
			if (!Mp[now])
			{
				cout<<"YES\n";
				for (int i=1;i<ans.size();i++) cout<<ans[i];
				cout<<endl;
				ans1=1;
				break;
			}
		}while (work());
		if (!ans1) cout<<"NO\n";
	}
}
/*
000
001
010
011
100
110
111

111
110


*/