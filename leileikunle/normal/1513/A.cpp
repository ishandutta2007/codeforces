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
#define cn change_number_tostring
#define cs change_string_tonumber
#define pri init_prime_distance
using namespace std;
const int N = 2e5+10;
int a[N],b[N];
map<int,int> mp;
void solve()
{
	int n,k; cin>>n>>k;
	for(int i=1;i<=n;i++) a[i]=i;
	if((n%2==0 && k>=n/2) || (n%2==1 && k>n/2))
	{
		cout<<-1<<endl;
		return;
	}
	int t = 2;
	for(int i=1;i<=k;i++)
	{
		int temp = a[t];
		a[t] = a[t+1];
		a[t+1] = temp;
		t+=2;
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<' ';
	cout<<endl;
	
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