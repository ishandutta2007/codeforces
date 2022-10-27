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

int m, n, l[mn], r[mn], a[mn];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>l[i]>>r[i];
	
	for (int i=1; i<=m; i++) a[i]=0;
	for (int i=1; i<=n; i++) for (int j=l[i]; j<=r[i]; j++) a[j]=1;
	int k=0;
	for (int i=1; i<=m; i++) if (a[i]==0) k++;
	cout<<k<<"\n";
	for (int i=1; i<=m; i++) if (a[i]==0) cout<<i<<' ';
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: