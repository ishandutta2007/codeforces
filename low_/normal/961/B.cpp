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

int a[mn], t[mn];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, k, ans=0;
	cin>>n>>k;
	for (int i=1; i<=n; i++) cin>>a[i];
	for (int i=1; i<=n; i++) 
	{
		cin>>t[i];
		if (t[i]==0) t[i]=1;
		else t[i]=0, ans+=a[i];
	}
	
	int pt1=1, pt2=k+1, m=0, tmp=0;
	for (int i=1; i<=k; i++) tmp+=a[i]*t[i];
	m=tmp;
	
	while (pt2<=n)
	{
		tmp-=a[pt1]*t[pt1];
		tmp+=a[pt2]*t[pt2];
		m=max(m, tmp);
		pt1++;
		pt2++;
	}
	
	cout<<ans+m;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: