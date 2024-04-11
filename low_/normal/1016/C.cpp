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

int n, A[3][mn*10];
int uturn[3][mn*10], bturn[3][mn*10], zigzag[3][mn*10];
int mcd[3][mn*10];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[1][i];
	for (int i=1; i<=n; i++) cin>>A[2][i];
	
	for (int i=0; i<3; i++) for (int j=0; j<mn*10; j++) uturn[i][j]=0, zigzag[i][j]=0, bturn[i][j]=0, mcd[i][j]=0;
	for (int i=1; i<3; i++) for (int j=1; j<=n; j++) mcd[i][j]=mcd[i][j-1]+A[i][j];
	
	//ZIG ZAG
	int ptr=0;
	for (int i=1; i<=n; i++)
	{
		if (i%2==1)
		{
			zigzag[1][i]=zigzag[1][i-1]+ptr*A[1][i];
			ptr++;
			zigzag[2][i]=zigzag[1][i]+ptr*A[2][i];
			ptr++;
		}
		else
		{
			zigzag[2][i]=zigzag[2][i-1]+ptr*A[2][i];
			ptr++;
			zigzag[1][i]=zigzag[2][i]+ptr*A[1][i];
			ptr++;
		}
	}
	
	//U-TURN
	ptr=0;
	for (int i=1; i<=n; i++) 
	{
		uturn[1][i]=uturn[1][i-1]+ptr*A[1][i];
		ptr++;
	}
	uturn[2][n]=uturn[1][n]+ptr*A[2][n];
	ptr++;
	for (int i=n-1; i>=1; i--) 
	{
		uturn[2][i]=uturn[2][i+1]+ptr*A[2][i];
		ptr++;
	}
	
//	for (int i=1; i<3; i++) 
//	{
//		for (int j=1; j<=n; j++) cerr<<uturn[i][j]<<' ';
//		cerr<<'\n';
//	}
	
	//U-TURN BACKWARDS
	ptr=0;
	for (int i=1; i<=n; i++)
	{
		bturn[2][i]=bturn[2][i-1]+ptr*A[2][i];
		ptr++;
	}
	bturn[1][n]=bturn[2][n]+ptr*A[1][n];
	ptr++;
	for (int i=n-1; i>=1; i--)
	{
		bturn[1][i]=bturn[1][i+1]+ptr*A[1][i];
		ptr++;
	}
	
	//SOLVE
	int ans=-inf;
	for (int i=0; i<=n; i++)
	{
		int ret=zigzag[(i%2)+1][i], temp;
//		if (i%2==0) ret=zigzag[1][i];
//		else ret=zigzag[2][i]
		
		if (i%2==0)
		{
			temp=max((int)0, uturn[2][i+1]-uturn[1][i]);
			temp+=i*(mcd[1][n]-mcd[1][i]+mcd[2][n]-mcd[2][i]);
		}
		else
		{
			temp=max((int)0, bturn[1][i+1]-bturn[2][i]);
			temp+=i*(mcd[1][n]-mcd[1][i]+mcd[2][n]-mcd[2][i]);
		}
		ans=max(ans, ret+temp);
	}
	
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: