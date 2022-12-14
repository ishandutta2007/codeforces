#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define pb push_back
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define for00 for(int i=1;i<=n;i++) cin>>a[i];
#define for0 for(int i=0;i<n;i++)
#define for1 for(int i=1;i<=n;i++)
#define for2(i,a,b) for(int i=a; i<=b;i++)
#define for3(i,a,b) for(int i=a; i>=b;i--)
#define all(a) begin(a), end(a)
#define SUM(a) accumulate(all(a), 0LL)
#define MIN(a) (*min_element(all(a)))
#define MAX(a) (*max_element(all(a)))
#define lb(a, x) distance(begin(a), lower_bound(all(a), (x)))
#define ub(a, x) distance(begin(a), upper_bound(all(a), (x)))
#define gcd __gcd
#define debug(x) cout<<"x="<<x<<endl
using namespace std;
int digit(int i) { stringstream ss; ss<<i; return ss.str().size(); }
const int N = 1e4+10;
string cs(int i) {  stringstream ss; ss<<i; return ss.str();  }
int st(string s) {  int num; stringstream ss(s);  ss>>num; return num;  }

void solve()
{
	int n; cin>>n;
	int ans = 0,flag = 1;
	int t = digit(n);
	ans += (t-1)*9;
	string s = cs(n);	
	for(int i=1;i<t;i++)
	{
		if(s[i]<s[0])
		{
			flag = 0;
		}
		if(s[i]==s[0])
		{
			continue;
		}
		if(s[i]>s[0]&&flag)
		{
			flag = 1; 
			break;
		}
	}
	if(flag) ans+=(s[0]-'0');
	else ans+=((s[0]-'0')-1);
	cout<<ans<<endl;
}

signed main()
{
	ios;
	int tt;
	cin>>tt;
	while(tt--)
	{
		solve();
	}
}