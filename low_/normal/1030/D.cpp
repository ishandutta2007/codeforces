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
#define mn 100005
#define FLN "test"

int m, n, k;
int GCD(int a, int b)
{
	if (b==0) return a;
	return GCD(b, a%b);
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>k;
	int g=GCD(m, k);
	int M=m/g;
	k/=g;
	g=GCD(n, k);
	int N=n/g;
	k/=g;
	
	if (k==2) cout<<"YES\n0 0\n0 "<<M<<"\n"<<N<<" 0";
	else if (k==1)
	{
		if (n>=N+N) cout<<"YES\n0 0\n0 "<<M<<"\n"<<N+N<<" 0";
		else cout<<"YES\n0 0\n0 "<<M+M<<"\n"<<N<<" 0";
	}
	else cout<<"NO";
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: https://codeforces.com/profile/low_