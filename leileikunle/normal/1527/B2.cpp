#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int IOS = []() {ios::sync_with_stdio(0); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#define pb push_back 	#define po pop_back
#define YES cout<<"YES\n" 	#define Yes cout<<"Yes\n"   #define NO cout<<"NO\n"	 #define No cout<<"No\n"
#define for00 for(int i=1;i<=n;i++) cin>>a[i];
#define for0 for(int i=0;i<n;i++)
#define for1 for(int i=1;i<=n;i++)
#define for2(i,a,b) for(int i=a; i<=b;i++)
#define for3(i,a,b) for(int i=a; i>=b;i--)
const int N = 2e5+10;

//inline int quick(int a, int b) { a%=mod; int res = 1;  while(b) { if(b & 1) res = res * a % mod; a = a * a % mod;  b >>= 1; } return res; }
void solve()
{
	int t; cin>>t;
	string s; cin>>s;
	int sum = 0 , sum1 = 0 , sum2 = 0;
	int flag1 = 0 , flag2 = 0 , flag3 = 0;
	
	for(int i=0;i<t;i++)
	{
		if(s[i]!=s[t-i-1] && s[i]!='1')
		{
			sum1++;
			s[i]='1';
		}
	}
	for(int i=0;i<t;i++)
	{
		if(s[i]=='0')
		{
			sum2++;
		}
	}
	if(sum1)
	{
		if(sum1==1)
		{
			if(sum2==1) cout<<"DRAW"<<endl;
			else cout<<"ALICE"<<endl; 
		}
		else{
			cout<<"ALICE"<<endl; 
		}
	}else
	{
		if(sum2==0)
		{
			cout<<"DRAW"<<endl;
		}
		else if(sum2==1 || sum2%2==0)
		{
			cout<<"BOB"<<endl;
		}
		else 
		{
			cout<<"ALICE"<<endl;
		}
	}
	return;
}
signed main()
{
	int tt=1;
	cin>>tt;
	while(tt--)
	{
		solve();
	}



}