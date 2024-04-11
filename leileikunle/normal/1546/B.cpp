#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
int IOS = []() {ios::sync_with_stdio(0); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#define endl '\n'
#define for00 for(int i=1;i<=n;i++) cin>>a[i];
#define for0 for(int i=0;i<n;i++)
#define for1 for(int i=1;i<=n;i++)
#define for2(i,a,b) for(int i=a; i<=b;i++)
#define for3(i,a,b) for(int i=a; i>=b;i--)
int a[N];
void solve()
{
	memset(a,0,sizeof a);
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		string s; cin>>s;
		for(int j=0;j<m;j++) a[j] ^= (s[j]-'a'+1);
	}
	for(int i=1;i<n;i++)
	{
		string s; cin>>s;
		for(int j=0;j<m;j++) a[j] ^= (s[j]-'a'+1);
	}
	for(int i=0;i<m;i++)
	{
		cout<<char(a[i]+'a'-1);
	}cout<<endl;
} 
signed main()
{
    int tt=1;
    cin>>tt;
    while(tt--)
    {
    	solve();
	}
    return 0;
}