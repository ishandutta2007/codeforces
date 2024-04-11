#include<iostream>
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

int A[14];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	for (int i=0; i<14; i++) cin>>A[i];
	
	int t1, t2, ans=0, q, r, r1;
	for (int i=0; i<14; i++) if (A[i]>0)
	{
		q=A[i]/14;
		r=A[i]%14;
		r1=r;
		
		t2=A[i];
		A[i]=0;
		for (int j=0; j<14; j++) A[j]+=q;
		t1=(i+1)%14;
		while (r--)
		{
			A[t1]++;
			t1=(t1+1)%14;
		}
		
		t1=0;
		for (int j=0; j<14; j++) 
		{
			t1+=A[j]*(int)(A[j]%2==0);
			A[j]-=q;
		}
		ans=max(ans, t1);
		
		t1=(i+1)%14;
		while (r1--)
		{
			A[t1]--;
			t1=(t1+1)%14;
		}
		
		A[i]=t2;
	}
	
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: