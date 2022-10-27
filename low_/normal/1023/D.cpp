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

int n, q;
int A[mn*2];

int l[mn*2]={0}, r[mn*2]={0};

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>q;
	A[0]=0;
	A[n+1]=0;
	for (int i=1; i<=n; i++) cin>>A[i];
	
	bool cntq=0;
	for (int i=1; i<=n; i++) if (A[i]==q) cntq=1;
	if (!cntq)
	{
		bool c0=0;
		for (int i=1; i<=n; i++) if (A[i]==0) 
		{
			A[i]=q, c0=1;
			break;
		}
		if (!c0)
		{
			cout<<"NO";
			return 0;
		}
	}
	
	for (int i=1; i<=n; i++) if (A[i]==0) A[i]=A[i-1];
	for (int i=n; i>=1; i--) if (A[i]==0) A[i]=A[i+1];
	
	if (A[1]==0)
	{
		cout<<"YES\n";
		for (int i=1; i<=n; i++) cout<<q<<' ';
		return 0;
	}
	
	for (int i=1; i<=q; i++) l[i]=inf, r[i]=-1;
	
	for (int i=1; i<=n; i++) l[A[i]]=min(l[A[i]], i), r[A[i]]=max(r[A[i]], i);
	
	vector <int> st={0};
	for (int i=1; i<=n; i++)
	{
		if (A[i]<st.back())
		{
			cout<<"NO";
			return 0;
		}
		
		if (i==l[A[i]]) st.push_back(A[i]);
		
		if (i==r[A[i]]) st.pop_back();
	}
	
	cout<<"YES\n";
	for (int i=1;i<=n; i++) cout<<A[i]<<' ';
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: