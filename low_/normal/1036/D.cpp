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

int m, n;
deque <int> A, B;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	A.assign(n, 0);
	for (int i=0; i<n; i++) cin>>A[i];
	cin>>m;
	B.assign(m, 0);
	for (int i=0; i<m; i++) cin>>B[i];
	
	int tt1=0, tt2=0;
	for (int i=0; i<n; i++) tt1+=A[i];
	for (int i=0; i<m; i++) tt2+=B[i];
	if (tt1!=tt2) cout<<-1;
	else
	{
		int ans=0;
		while (A.size()>0 && B.size()>0)
		{
			if (A.front()==B.front()) A.pop_front(), B.pop_front(), ans++;
			else if (A.front()<B.front())
			{
				int t=A.front();
				A.pop_front();
				A[0]+=t;
			}
			else if (A.front()>B.front())
			{
				int t=B.front();
				B.pop_front();
				B[0]+=t;
			}
		}
		
		cout<<ans;
	}
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: