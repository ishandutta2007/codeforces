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
//#define N
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,k,now,n,b[15];
string st,ans;
set<int>S;
signed main()
{
	ios::sync_with_stdio(false);
	cin>>T;
	while (T--)
	{
		cin>>st>>k;string stt=st;
		n=st.length();ans="";
		st=' '+st;now=0;
		S.clear();
		for (int i=1;i<=n;i++)
		{
			int x=st[i]-'0';
			if (now<k)
			{
				string st1="";
				for (int j=1;j<i;j++) st1+=st[j];
				st1+=char(x+'0'+1);
				if (now+(b[x+1]==0)<k)
				for (int j=i+1;j<=n;j++) st1+='0';
				else
				for (int j=i+1;j<=n;j++) st1+='0'+((S.empty()^1)?min(x+1,(*S.begin())):(x+1));
				ans=st1;
			}
			else
			if (now==k)
			{
				string X="",Y="";
				for (int j=i;j<=n;j++) X+=st[j];
				for (int j=i;j<=n;j++) Y+=x+'0';
				x++;auto it=S.lower_bound(x);
				if (it!=S.end()) 
				{
					string st1="";
					for (int j=1;j<i;j++) st1+=st[j];
					st1+=(*it)+'0';
					for (int j=i+1;j<=n;j++) st1+=char((*S.begin())+'0');
					ans=st1;
				}
				x--;
//				cout<<X<<" "<<Y<<endl;
				if (X<=Y)
				{
					auto it=S.lower_bound(x);
//					cout<<"nm"<<(*it)<<endl;
					if (it!=S.end()) 
					{
						if ((*it)==x)
						{
							string st1="";
							for (int j=1;j<i;j++) st1+=st[j];
							for (int j=i;j<=n;j++) st1+=char((*it)+'0');
							ans=st1;
						}
					}
				}
				
			}
			x=st[i]-'0';
			S.insert(x);
			b[x]++;
			if (b[x]==1) now++;
		}
		if (now<=k) ans=stt;
		if (ans=="")
		{
			ans+="1";
			for (int i=1;i<=n;i++)
				if (k==1) ans+="1";
				else ans+="0";
		}
		for (int i=0;i<=9;i++) b[i]=0;
		cout<<ans<<endl;
	}
				
}
/*

*/