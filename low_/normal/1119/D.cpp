#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<queue>
using namespace std;
#define int long long
#define mn 100005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test"
#define pii pair <int, int>
#define XX first
#define YY second

int n, S[mn];
vector <int> diff={};

int BS(int u)
{
	int l=0, r=diff.size();
	while (r>l)
	{
		int mid=(l+r)/2;
		
		if (diff[mid]<=u) l=mid+1;
		else r=mid;
	}
	return l;
}

signed main()
{
#ifdef lowie
	freopen(FLN".inp", "r", stdin);
	freopen(FLN".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for (int i=1; i<=n; i++) cin>>S[i];
	
	sort(S+1, S+n+1);
	for (int i=1; i<n; i++) diff.push_back(S[i+1]-S[i]);
	sort(diff.begin(), diff.end());
//	for (int i:diff) cerr<<i<<" ";
//	cerr<<"\n";
	vector <int> mcdDiff={0};
	for (int i=0; i<diff.size(); i++) mcdDiff.push_back(mcdDiff.back()+diff[i]);
//	for (int i:mcdDiff) cerr<<i<<" ";
//	cerr<<"\n";
	
	
	int q, l, r;
	cin>>q;
	while (q--)
	{
		cin>>l>>r;
		int s=r-l+1;
		int x=BS(s); //So phan tu nho hon s trong day diff
//		cerr<<s<<" "<<x<<"\n";
		cout<<mcdDiff[x]+(n-x)*s<<" ";
		
	}
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/