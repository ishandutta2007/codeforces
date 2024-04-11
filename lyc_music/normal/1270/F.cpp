//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
//#define int ll
#define N 200005
#define B 205
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
string st;
int l[N],s[N];
unordered_map<int,int>b;
int n;
ll ans;
int query(int l,int r,int k)
{
//	cout<<"/"<<l<<" "<<r<<" "<<k<<endl;
	int L=(l/k)*k,R=(r/k)*k;
	if (L<l) L+=k;
	L=max(L,k*(B+1));
	if (L>R) return 0;
	return ((R-L)/k+1);
}
signed main()
{
//	IOS;
	cin>>st;
	n=st.length();
	st=' '+st;
	int lst=0;
	for (int i=1;i<=n;i++)
	{
		l[i]=lst;
		s[i]=s[i-1];
		if (st[i]=='1') lst=i,s[i]++;
	}
//	if (s[n]==n&&n>1000) return puts("!"),0;
	for (int i=1;i<=n;i++)
	{
		int now=i;
		if (st[i]!='1') now=l[i];
		while (now&&(s[i]-s[now-1])<=(n/B+5))
		{
			ans+=query(i-now+1,i-l[now],s[i]-s[now-1]);
			now=l[now];
		}
//		cout<<"?"<<i<<endl;
	}
	for (int j=1;j<=B;j++)
	{
		b[0]=1;
		for (int i=1;i<=n;i++)			
			ans+=b[j*s[i]-i],
			b[j*s[i]-i]++;
		b.clear();
	}
	cout<<ans<<endl;
	
	
}
/*

*/