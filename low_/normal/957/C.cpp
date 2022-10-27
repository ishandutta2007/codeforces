#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long
#define mod 1000000007
#define inf 9223372036854775799
#define mn 100005

int n, E[mn], U;

int CNP(int u, int l, int r)
{
	if (u<E[l]) return l-1;
	if (u>=E[r]) return r;
	
	int m=(l+r)/2;
	
	if (u>=E[m]) return CNP(u, m+1, r);
	else return CNP(u, l, m);
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>U;
	
	for (int i=1; i<=n; i++) cin>>E[i];
	
	double ans=-1;
	
	for (int i=1; i<n; i++)
	{
		int c=CNP(E[i]+U, i+1, n);
		if (c==i || c==i+1) continue;
		
	//	cout<<i<<" "<<i+1<<" "<<c<<"\n";
		ans=max((double)(E[c]-E[i+1])/(double)(E[c]-E[i]), ans);
	}
	
	if (ans+1<(double)0.000000001) cout<<-1;
	else printf("%0.9f", ans);
}