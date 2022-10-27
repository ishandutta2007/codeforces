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

int r[105], c[105], R[105][64], C[105][64];
int m, n;
int ans[105][105][64];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	for (int i=0; i<105; i++) for (int j=0; j<64; j++) R[i][j]=0, C[i][j]=0;
	for (int i=0; i<105; i++) for (int j=0; j<105; j++) for (int k=0; k<64; k++) ans[i][j][k]=0;
	
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>r[i];
	for (int i=1; i<=m; i++) cin>>c[i];
	
	for (int i=1; i<=n; i++)
	{
		int ptr=0;
		while (r[i]>0) 
		{
			R[i][ptr]=r[i]%2;
			r[i]/=2;
			ptr++;
		}
	}
	for (int i=1; i<=m; i++)
	{
		int ptr=0;
		while (c[i]>0)
		{
			C[i][ptr]=c[i]%2;
			c[i]/=2;
			ptr++;
		}
	}
	
	int Rcnto, Rcnte, Rindo, Rinde, Ccnto, Ccnte, Cindo, Cinde;
	for (int bit=0; bit<33; bit++)
	{
//		cerr<<bit<<":\n";
		Rcnto=0, Rcnte=0, Rindo=-1, Rinde=-1, Ccnto=0, Ccnte=0, Cindo=-1, Cinde=-1;
		
		for (int i=1; i<=n; i++)
		{
			if (R[i][bit]==0) Rinde=i, Rcnte++;
			else Rindo=i, Rcnto++;
		}
		for (int i=1; i<=m; i++)
		{
			if (C[i][bit]==0) Cinde=i, Ccnte++;
			else Cindo=i, Ccnto++;
		}
		
		if ((Rcnto%2)!=(Ccnto%2)) 
		{
			cout<<"NO";
			return 0;
		}
		
		
		if (Rcnto==0 || Ccnto==0) 
		{
			for (int i=1; i<=m; i++) if (C[i][bit]==1) ans[Rinde][i][bit]=1;
			for (int i=1; i<=n; i++) if (R[i][bit]==1) ans[i][Cinde][bit]=1;
		}
		else
		{
			int i=1, j=1;
			while (Ccnto>0 || Rcnto>0)
			{
//				cerr<<Ccnto<<' '<<Rcnto<<'\n';
				if (Rcnto>0) 
				{
					while (R[i][bit]==0) i++;
					Rcnto--;
				}
				if (Ccnto>0) 
				{
					while (C[j][bit]==0) j++;
					Ccnto--;
				}
				ans[i][j][bit]=1;
				if (Rcnto>0) i++;
				if (Ccnto>0) j++;
			}
		}
	}
	
	for (int bit=32; bit>=0; bit--) for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) ans[i][j][40]=ans[i][j][40]*2+ans[i][j][bit];
	cout<<"YES\n";
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++) cout<<ans[i][j][40]<<' ';
		cout<<'\n';
		
	}
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: