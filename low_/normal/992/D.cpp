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
#define inf 1000000000000000001
#define mn 300005
#define FLN "test"

int n, A[mn], k;
int mcd[mn]; //mcdprd[mn];
int Prv[mn], ptr=0;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	mcd[0]=0;
	cin>>n>>k;
	for (int i=1; i<=n; i++) 
	{
		cin>>A[i];
		mcd[i]=mcd[i-1]+A[i];
	}
	
	for (int i=1; i<=n; i++)
	{
		Prv[i]=ptr+1;
		if (A[i]>1) ptr=i;
//		cerr<<i<<": "<<Prv[i]<<"\n";
	}
	
	
	int ans=0;
	for (int i=1; i<=n; i++)
	{
		int curprd=1;
		
		int ptr=i;
		while (ptr>0)
		{
			if (inf/A[ptr]<=curprd) break;
			curprd*=A[ptr];
			
			int l=(mcd[i]-mcd[ptr-1])*k;
			ptr=Prv[ptr];
			if (ptr<=0) break;
			int r=(mcd[i]-mcd[ptr-1])*k;
			if (curprd%k==0 && curprd>=l && curprd<=r) ans++;
		//	cerr<<i<<" "<<ptr<<"\n"<<curprd<<" "<<l<<' '<<r<<"\n";
			ptr--;
		//	cerr<<ptr<<"\n\n";
		}
	}
	
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: