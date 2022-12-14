#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb push_back
#define po pop_back
#define YES cout<<"YES\n" 	#define Yes cout<<"Yes\n"
#define NO cout<<"NO\n"		#define No cout<<"No\n"
#define for00 for(int i=1;i<=n;i++) cin>>a[i];
#define for0 for(int i=0;i<n;i++)
#define for1 for(int i=1;i<=n;i++)
#define for2(i,a,b) for(int i=a; i<=b;i++)
#define for3(i,a,b) for(int i=a; i>=b;i--)
//#define * {cout<<""; return;}
//#define ** {cout<<""; return;}
const int mod = 1e9+7;
const int sp = 1e9;
typedef long long ll;
const int ma = 3e5+10;
using namespace std;
int judge(string s)
{
	int t = s.size();
	int ans = 0;
	for(int i=0;i<t;i++)
	{
		if(s[i]=='(') ans++;
		else{
			if(ans<=0)
			{
				return 0;
			}else ans--;
		}
	}
	if(ans==0) return 1;
	else return 0;
}
char x,y,z;
void solve()
{
	string s; cin>>s;
	string ss = s;
	int t = s.size();
	int flag = 0;
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=2;j++)
		{
			for(int k=1;k<=2;k++)
			{
				if(i==1)  x='('; if(i==2) x=')';
				if(j==1)  y='('; if(j==2) y=')';
				if(k==1)  z='('; if(k==2) z=')';
				for(int i=0;i<t;i++)
				{
					if(s[i]=='A') s[i]=x;
					if(s[i]=='B') s[i]=y;
					if(s[i]=='C') s[i]=z;
				}
				//cout<<s<<'\n';
				if(judge(s))
				{
					flag = 1;
					break;
				}
				s = ss;
			}
		}
	}
	if(flag) cout<<"YES\n";
	else cout<<"NO\n"; 
}
signed main()
{
	ios;
	int tt; cin>>tt;
	while(tt--)
	{
		solve();
	}
	
}