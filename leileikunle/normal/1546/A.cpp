#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4+10;
int IOS = []() {ios::sync_with_stdio(0); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#define endl '\n'
#define for00 for(int i=1;i<=n;i++) cin>>a[i];
#define for0 for(int i=0;i<n;i++)
#define for1 for(int i=1;i<=n;i++)
#define for2(i,a,b) for(int i=a; i<=b;i++)
#define for3(i,a,b) for(int i=a; i>=b;i--)
int a[N],b[N];
pair<int,int> c[N];
void solve()
{
	int cnt=0,res=0;
	set<int> s;
	int sum=0;
	int q,w; q=w=0;
	int n; cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],q+=a[i];
	for(int i=1;i<=n;i++) cin>>b[i],w+=b[i];
	if(q!=w)
	{
		cout<<-1<<endl;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]>b[i]) s.insert(i);
	}
	for(int i=1;i<=n;i++)
	{
		while(a[i]<b[i])
		{
			auto t = *s.begin();
			if(a[t]>b[t])
			{
				c[++cnt] = {t,i};
				a[t]--;
				a[i]++;
			}
			if(a[t]==b[t])
			{
				s.erase(t);
			}
		}
	}
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++) cout<<c[i].first<<" "<<c[i].second<<endl;
	
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