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

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, k;
	cin>>n>>k;
	char Ans[5][100];
	bool cor=1;
	
	for (int i=1; i<=n; i++) Ans[1][i]='.', Ans[2][i]='.',  Ans[3][i]='.', Ans[4][i]='.';
	
	if (k%2==0) for (int i=2; i<2+k/2; i++) Ans[2][i]='#', Ans[3][i]='#';
	else if (k%2==1)
	{
		if (k<=n-2) for (int i=(n-k)/2+1; i<=(n+k)/2; i++) Ans[2][i]='#';
		else 
		{
			for (int i=2; i<=n-1; i++) Ans[2][i]='#', Ans[3][i]='#';
			k=2*(n-2)-k;
			for (int i=(n-k)/2+1; i<=(n+k)/2; i++) Ans[2][i]='.';
		}
	}
	
//	if (cor)
//	{
		cout<<"YES\n";
		for (int i=1; i<=4; i++) 
		{
			for (int j=1; j<=n; j++) cout<<Ans[i][j];
			cout<<"\n";
		}
//	}
//	else cout<<"NO";
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: