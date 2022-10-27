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

set <int> ans, ans2;

int n, k, a[mn];

int GCD(int a, int b)
{
	if (b==0) return a;
	if (a%b==0) return b;
	return GCD(b, a%b);
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	for (int i=1; i<=n; i++) cin>>a[i];
	
	ans2.insert(0);
	for (int i=1; i<=n; i++) ans.insert(GCD(a[i], k));
	for (int i:ans) for (int j:ans) ans.insert(GCD(i, j));
	for (int i:ans) if (ans2.count(i)==0) for (int j=1; j*i<k; j++) ans2.insert(i*j);
	
	cout<<ans2.size()<<"\n";
	for (int i:ans2) cout<<i<<' ';
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: