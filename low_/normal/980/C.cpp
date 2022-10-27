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

int n,k, C[mn], Ans[mn];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	for (int i=1; i<=n; i++) cin>>C[i];
	
	int Clr[256], t1, t2;
	for (int i=0; i<256; i++) Clr[i]=-1;
	Clr[0]=0;
	
	for (int i=1; i<=n; i++)
	{
		if (Clr[C[i]]!=-1) Ans[i]=Clr[C[i]];
		else
		{
			t1=C[i];
			while (Clr[t1]==-1)
			{
				if (C[i]-t1+1==k) break;
				t1--;
			}
			
			if (Clr[t1]!=-1) 
			{
				if (C[i]-Clr[t1]+1<=k) t1=Clr[t1];
				else t1++;
			}
			
			for (int j=t1; j<=C[i]; j++) Clr[j]=t1;
			
			Ans[i]=t1;
		}
		
	}
	
	for (int i=1; i<=n; i++) cout<<Ans[i]<<" ";
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: