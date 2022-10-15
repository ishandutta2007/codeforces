//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define inf 1e18
#define mod 998244353
//#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
pa a[N];
string st;
int t;
int l,r;
int n;
int x;
int y;
signed main()
{
	IOS;
	cin>>n;
	for (int i=1;i<=n;i++) 
	{
		int q;
		cin>>q;
		a[i]={q,i};
	}
	sort(a+1,a+n+1);
	cin>>st;
	for (int i=1;i<st.length();i++)
		if (st[i]!=st[i-1]) x++;
	int l=n-x,r=n-x+1;
	if (st[0]=='L') t=1;
	cout<<a[l].fi<<" "<<st[0]<<endl;
	l--;
	for (int i=1;i<st.length();i++)	
	{
		if (st[i]!=st[i-1])
		{
			cout<<a[r].fi<<" "<<st[i]<<endl;
			r++;
		}
		else
		{
			if (t)
			cout<<a[l].fi<<" "<<'R'<<endl;
				else 
			cout<<a[l].fi<<" "<<'L'<<endl;
			t^=1;
			l--;
		}
	}
}
/*

*/