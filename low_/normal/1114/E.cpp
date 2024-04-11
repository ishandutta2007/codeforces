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

int GCD(int u, int v)
{
	if (v==0) return u;
	return GCD(v, u%v);
}

int rand_l()
{
	int ret=rand();
	ret=(ret<<15)+(int)rand();
	ret=(ret<<15)+(int)rand();
	return ret;
}


signed main()
{
	srand(time(0));
	int n;
	cin>>n;
	int l=0, r=1000*1000*1000;
	int cnt=0;
	while (r>l)
	{
		int mid=(l+r)/2;
		cout<<"> "<<mid<<endl;
		cnt++;
		int t;
		cin>>t;
		if (t==0) r=mid;
		else l=mid+1;
	}
	
	cnt=60-cnt;
	int ans=0;
	while (cnt--)
	{
		int a=rand_l()%n+1;
		cout<<"? "<<a<<endl;
		int t;
		cin>>t;
		ans=GCD(ans, l-t);
	}
	int a1=l-(n-1)*ans;
	cout<<"! "<<a1<<" "<<ans<<endl;
	exit(0);
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/