//The Hunting Party - Keys To The Kingdom
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 5005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
string st;
int n,a[N],s[N],ans;
int f[N][N];
void LYC_music()
{
	cin>>st;
	n=st.length();
	st=' '+st;
	for (int i=1;i<=n;i++)
	{
		int now=0;
		int x=0,y=0;
		for (int j=i;j<=n;j++)
		{
			if (st[j]=='(') now++;
			else
			if (st[j]==')')
			{
				while (now<=0)
				{
					if (y==0) break;
					now+=2;
					y-=1;
				}
				if (now<=0) break;
				now--;
			}
			else
			if (st[j]=='?')
			{
				if (now<=0) x++,now++;
				else
				{
					y++,now--;
				}
			}
			if (now+2*y>=0) 
			{
				ans+=((now<=0)&&(j-i)%2);
//				if (((now<=0)&&(j-i)%2)) cout<<i<<" "<<j<<" "<<now<<endl;
			}
			else break;
		}
	}
	writeln(ans);
}
signed main()
{
	int T=1;
	while (T--)
	{
		LYC_music();
	}
}
/*
()()((?(()(((()()(())(((()((())))(()))(()(((((())))()))(((()()()))))))(((((()))))))))
*/