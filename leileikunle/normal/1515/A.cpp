#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define for00 for(int i=1;i<=n;i++) cin>>a[i];
#define for0 for(int i=0;i<n;i++)
#define for1 for(int i=1;i<=n;i++)
#define for2(i,a,b) for(int i=a; i<=b;i++)
#define for3(i,a,b) for(int i=a; i>=b;i--)
using namespace std;

const int N = 2e3+10;
int a[N],b[N];
void solve()
{
	int n,x; cin>>n>>x;
	int sum = 0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		b[a[i]]++;
	}
	if(sum==x||(b[a[1]]==n && a[1]==x))
	{
		cout<<"NO"<<endl;
		return;
	}
	cout<<"YES"<<endl;
	sort(a+1,a+n+1);
	if(sum<x)
	{
		for1 cout<<a[i]<<" ";
		cout<<endl;
		return;
	}
	int q= 0 ;
	multiset<int> st;
	for(int i=1;i<=n;i++)
	{
		if(q+a[i]==x) 
		{
			st.insert(a[i]);
			continue;
		}else{
			q+=a[i];
			cout<<a[i]<<" ";
		}
	}
	while(!st.empty())
	{
		cout<<*st.begin()<<" ";
		auto t = st.find(*st.begin());
		st.erase(t);
	}
	cout<<endl;
}
signed main()
{
	ios;
	int tt = 1;
	cin>>tt;
	while(tt--)
	{
		solve();
	}
	


}