#include <bits/stdc++.h>
using namespace std;
#define int long long
int IOS = []() {ios::sync_with_stdio(0); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#define endl '\n'
const int N = 2e5+10,inf = 1e9+10,mod = 1e9+7;
int a[N],ans,n,r;
vector<int> v;
int solve1(int l,int r) 
{
    v.clear();
    for(int i=l;i<=r;i++)
	{
        if(a[i]>=-inf&&a[i]<=inf) 
		{
            if(upper_bound(v.begin(),v.end(),a[i])==v.end()) v.emplace_back(a[i]);
            else *upper_bound(v.begin(),v.end(),a[i])=a[i];
        }
    }
    int t = v.size();
    return t;
}
int solve2(int l,int r) 
{
    v.clear();
    for(int i=l;i<=r;i++)
    {
        a[i]=-a[i];
        if(a[i]>=-inf&&a[i]<=inf) 
		{
            if(upper_bound(v.begin(),v.end(),a[i])==v.end()) v.emplace_back(a[i]);
            else *upper_bound(v.begin(),v.end(),a[i])=a[i];
        }
        a[i]=-a[i];
    }
    int t = v.size();
    return t;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	ans=0,r=0;
    for(int i=1;i<=n;i++)
	{
    	while(true) 
    	{
    		if(r<=n-1&&solve1(i,r+1)<=2&&solve2(i,r+1)<=2) r++;
    		else break;
		}
		int t = r-i+1;
		ans+=t;
    }
    cout<<ans<<endl;
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