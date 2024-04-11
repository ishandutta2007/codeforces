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
#define inf 922337203685477579
#define mn 100005

int n, X1, X2;
pair <int, int> C[mn*3];

int CNP(int u, int l, int r)
{
	if (u<C[l].first) return l;
	if (u>=C[r].first) return r+1;
	
	int m=(l+r)/2+1;
	
	if (u<C[m].first) return CNP(u, l, m-1);
	else return CNP(u, m, r);
}

int Cr1[mn*3], Cr2[mn*3]; 

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>X1>>X2;
	for (int i=1; i<=n; i++) 
	{
		cin>>C[i].first;
		C[i].second=i;
	}
	
	sort(C+1, C+n+1);
	
	for (int i=0; i<=n+1; i++)
	{
		Cr1[i]=inf;
		Cr2[i]=inf;
	}
	
	for (int i=1; i<=n; i++)
	{
		int p1=CNP(X1/i-(int)(X1%i==0), 1, n), p2=CNP(X2/i-(int)(X2%i==0), 1, n);
		Cr1[p1]=min(Cr1[p1], i);
		Cr2[p2]=min(Cr2[p2], i);
	}
	
	for (int i=1; i<=n+1; i++)
	{
		Cr1[i]=min(Cr1[i], Cr1[i-1]);
		Cr2[i]=min(Cr2[i], Cr2[i-1]);
		
	}
	
	int M1=-1, M2=-1;
	for (int i=n; i>=1; i--) if (i+Cr1[i]-1<=n) 
	{
		M1=i;
		break;
	}
	for (int i=n; i>=1; i--) if (i+Cr2[i]-1<=n)
	{
		M2=i;
		break;
	}
	
//	cerr<<M1<<" "<<M2<<"\n";
	
	if (M1==-1 || M2==-1) 
	{
		cout<<"No";
		return 0;
	}
	
	for (int i=1; i<n; i++) if (i+Cr1[i]-1<M2)
	{
//		cerr<<i<<" "<<Cr1[i]<<" "<<M2;
		cout<<"Yes\n"<<Cr1[i]<<" "<<n-M2+1<<"\n";
		for (int j=i; j<i+Cr1[i]; j++) cout<<C[j].second<<" ";
		cout<<"\n";
		for (int j=M2; j<=n; j++) cout<<C[j].second<<" ";
		return 0;
	}
	
	for (int i=1; i<n; i++) if (i+Cr2[i]-1<M1)
	{
//		cerr<<i<<" "<<Cr2[i]<<" "<<M1;
		cout<<"Yes\n"<<n-M1+1<<" "<<Cr2[i]<<"\n";
		for (int j=M1; j<=n; j++) cout<<C[j].second<<" ";	
		cout<<"\n";
		for (int j=i; j<i+Cr2[i]; j++) cout<<C[j].second<<" ";
		return 0;
	}
		
	cout<<"No";
}