#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<bitset>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;

#define X first
#define Y second

const int MaxN=100010;
const ld pi=acos(-1);

int n;
vector<ld> v;

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v.push_back(atan2(y,x));
		v.push_back(atan2(y,x)+pi*2);
	}
	sort(v.begin(),v.end());
	ld ans=1e20;
	for (int i=0;i<n;++i)
		ans=min(ans,v[i+n-1]-v[i]);
	printf("%.20lf\n",(double)(ans/pi*180));
	return 0;
}