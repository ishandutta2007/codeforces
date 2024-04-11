#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<cstdio>
using namespace std;
#define int long long
#define inf 92233720368547757
#define mn 300005
#define FLN "test"

int n, a[mn];
int IP[15000005], cnt[15000005];


map <int, int> primes;

int GCD(int a, int b)
{
	if (b==0) return a;
	return GCD(b, a%b);
}

bool fcheck()
{
	for (int i=1; i<=n; i++) if (a[i]>1) return false;
	return true;
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	IP[0]=IP[1]=0;
	for (int i=2; i<15000005; i++) IP[i]=i, cnt[i]=0;
	for (int i=2; i<15000005; i++) if (IP[i]==i) 
	{
		for (int j=i; j<15000005; j+=i) IP[j]=i;
	}
	
	cin>>n;
	for (int i=1; i<=n; i++) cin>>a[i];
	
	int g=a[1];
	for (int i=2; i<=n; i++) g=GCD(g, a[i]);
	for (int i=1; i<=n; i++) a[i]/=g;
	
 	if (fcheck())
 	{
 		cout<<-1;
 		return 0;
	 }
	
	set <int> ss;
	for (int i=1; i<=n; i++)
	{
		ss.clear();
		int t=a[i];
		while (t>1)
		{
			ss.insert(IP[t]);
			t/=IP[t];
		}
		
		for (int j:ss) cnt[j]++;
	}
	int ans=0;
	for (int i=2; i<15000005; i++) ans=max(ans, cnt[i]);
	cout<<n-ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: https://codeforces.com/profile/low_