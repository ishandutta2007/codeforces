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

int n, a[mn*2], b[mn*2];
vector <int> poss;

void rut()
{
	sort(poss.begin(), poss.end());
	vector <int> N=poss;
	while (poss.size()>1) poss.pop_back();
	for (int i=1; i<N.size(); i++) if (N[i]!=N[i-1]) poss.push_back(N[i]);
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for (int i=1; i<=n; i++) cin>>a[i]>>b[i];
	
	int t1=a[1], t2=b[1];
	int ptr=2;
	while (ptr*ptr<=a[1])
	{
		if (t1==1) break;
		while (t1%ptr==0) poss.push_back(ptr), t1/=ptr;
		ptr++;
	}
	if (t1>1) poss.push_back(t1);
	
	ptr=2;
	while (ptr*ptr<=b[1])
	{
		if (t2==1) break;
		while (t2%ptr==0) poss.push_back(ptr), t2/=ptr;
		ptr++;
	}
	if (t2>1) poss.push_back(t2);
	rut();
	
	for (int i=0; i<poss.size(); i++)
	{
		bool B=0;
		for (int j=2; j<=n; j++) if (a[j]%poss[i]!=0 && b[j]%poss[i]!=0) B=1;
		if (!B)
		{
			cout<<poss[i]<<'\n';
			return 0;
		}
	}
	cout<<-1;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: