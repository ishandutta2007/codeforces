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
bool l[mn], r[mn]; // l[i] - to check that if i is the leftmost position of the number A[i]
set <int> ss;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	
	for (int i=0; i<mn; i++) l[i]=0, r[i]=0;
	ss.clear();
	for (int i=1; i<=n; i++) if (ss.count(A[i])==0)
	{
		ss.insert(A[i]);
		l[i]=1;
	}
	ss.clear();
	for (int i=n; i>=1; i--) if (ss.count(A[i])==0)
	{
		ss.insert(A[i]);
		r[i]=1;
	}
	
	int cnt=0, ans=0;
	for (int i=1; i<=n; i++)
	{
		if (r[i]) ans+=cnt;
		if (l[i]) cnt++;
	}
	
	cout<<ans;
	
	
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: