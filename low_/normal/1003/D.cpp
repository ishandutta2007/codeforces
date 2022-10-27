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

map <int, int> pwr;
int pow2[100], coin[100];
int n, q, x;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	pwr.clear();
	int p=0;
	for (int i=1; i<=1000000000; i*=2)
	{
		pwr[i]=p, pow2[p]=i;
		coin[p]=0;
		p++;
	}

//	cerr<<(int)log2(1000000000);
	cin>>n>>q;
	while (n--)
	{
		cin>>x;
		coin[pwr[x]]++;
	}
	
	while (q--)
	{
		cin>>x;
		int t=29, ans=0, temp;
		while (t>-1)
		{
			temp=min(coin[t], x/pow2[t]);
			ans+=temp;
			x-=temp*pow2[t];
			t--;
		}
		
		if (x==0) cout<<ans<<"\n";
		else cout<<"-1\n";
	}
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: