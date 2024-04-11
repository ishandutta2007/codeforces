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

vector <int> V[15];

int N, K, A[mn*2];
int POW10[11]={1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000};

int scs(int k)
{
	int ret=0;
	while (k>0) k/=10, ret++;
	return ret;
}

int BNS(int cs, int u, int l, int r)
{
	if (u<=V[cs][l]) return (l-1);
	if (u>V[cs][r]) return r;
	
	int mid=(l+r)/2+1;
	
	if (u<=V[cs][mid]) return BNS(cs, u, l, mid-1);
	else return BNS(cs, u, mid, r);
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>N>>K;
	for (int i=1; i<=N; i++) cin>>A[i];
	
	for (int j=1; j<=10; j++) 
	{
		for (int i=1; i<=N; i++) V[j].push_back(((A[i]%K)*(POW10[j]%K))%K);
		sort(V[j].begin(), V[j].end());
	}
	
	
	int ans=0;
	for (int i=1; i<=N; i++)
	{
		int j=scs(A[i]);
		int l=BNS(j, (K-A[i]%K)%K+1, 0, V[j].size()-1);
		int r=BNS(j, (K-A[i]%K)%K, 0, V[j].size()-1);
		ans+=l-r-((((A[i]*(POW10[j]%K))%K+A[i])%K)==0);
	}
	
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: