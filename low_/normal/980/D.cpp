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
#define inf 9223372036854775799
#define mn 100005
#define FLN "test"

int n, A[mn];
int IP[mn];
vector <int> Primes;

int rutgon(int q)
{
	if (q==0) return 0;
	set <int> ss;
	ss.clear();
	for (int i=0; i<Primes.size(); i++) 
	{
		while (q%Primes[i]==0)
		{
			if (ss.count(Primes[i])==1) ss.erase(Primes[i]);
			else ss.insert(Primes[i]);
			q/=Primes[i];
		}
	}
	
	int ret=q;
	for (int j:ss) ret*=j;
	return ret;
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	for (int i=0; i<mn; i++) IP[i]=i;
	for (int i=2; i<mn; i++) if (IP[i]==i) for (int j=i; j*i<mn; j++) IP[i*j]=i;
	for (int i=2; i<10000; i++) if (IP[i]==i) Primes.push_back(i);
	
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	
	for (int i=1; i<=n; i++) 
	{
		A[i]=rutgon(A[i]);
//		cerr<<A[i]<<' ';
	}
//	cerr<<'\n';
	
	set <int> ss;
	ss.clear();
	int ans[5005];
	for (int i=1; i<=n; i++) ans[i]=0;
	for (int i=1; i<=n; i++) ss.insert(A[i]);
	map <int, int> MAP;
	int ptr=1;
	
	for (int j:ss) 
	{
		MAP[j]=ptr;
		ptr++;
	}
	
	for (int i=1; i<=n; i++) if (A[i]!=0) A[i]=MAP[A[i]];
	
//	for (int i=1; i<=n; i++) cerr<<A[i]<<' ';
	
//	cerr<<"\n";
	
	int cnt[5005]={1}, ct;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++) cnt[j]=0;
		ct=0;
		for (int j=i; j<=n; j++)
		{
			if (cnt[A[j]]==0) ct++, cnt[A[j]]++;
			ans[max((int)1, ct)]++;
		}
	}
	
	for (int i=1; i<=n; i++) cout<<ans[i]<<' ';
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: