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
void solve()
{
	int n; cin>>n;
	int sum = 0;
	for(int i=1;i<=n+2;i++)  cin>>a[i];
	sort(a+1,a+n+2+1);
	for(int i=1;i<=n+2;i++)  sum+=a[i];
	int flag = 0;
	for(int i=1;i<=n+2;i++)
	{
		int ans = sum-a[i];
		if(i!=n+2)
		{
			if(ans == 2*a[n+2])
			{
				for(int j=1;j<=n+1;j++)
				{
					if(j!=i) cout<<a[j]<<" ";
					flag=1;
				}
				cout<<endl;
				break;
			}
		}else{
			if(ans == 2*a[n+1])
			{
				for(int j=1;j<=n;j++)
				{
					cout<<a[j]<<" ";
					flag=1;
				}
				cout<<endl;
				break;
			}
		}
	}
	if(!flag) cout<<-1<<endl;
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