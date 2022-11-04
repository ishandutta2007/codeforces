#pragma comment(linker,"/STACK:102400000,102400000") 
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
#include <climits>
#include <cstdio>
#include <complex>
#include <numeric>
#include <cassert>
#define endl '\n'
#define PII pair<int,int>
#define	PD pair<double,double>
#define PDI pair<double,int>
#define ll long long
#define Fori(x) for(int i=0;i<x;i++)
#define Forj(x) for(int j=0;j<x;j++)
#define For1i(x) for(int i=1;i<=x;i++)
#define For1j(x) for(int j=1;j<=x;j++)
#define For(i,n) for(int i=0;i<n;i++)
#define y1 asdfeawf
using namespace std;
const int INF = 2147483647;
const int mod = 1000000007;
const double eps= 1e-8;
const long double pi = acosl(-1.0);
const int maxn = 1234567;


string str[100011];
ll a[100011];
int b[100011];
ll money[100011];
map<string,ll> ma;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll n,k,m;
	cin>>n>>k>>m;
	Fori(k)
		money[i] = 1000000011;
	Fori(n)
		cin>>str[i];
	Fori(n)
		cin>>a[i];
	Fori(k)
	{
		int fk;
		cin>>fk;
		Forj(fk)
		{
			int tmp;
			cin>>tmp;
			tmp--;
			b[tmp] = i;
			money[i] = min(money[i],a[tmp]);
		}
	}
	Fori(n)
	{
		a[i] = money[b[i]];
		ma[str[i]] = a[i];
	}
	ll ans = 0;
	Fori(m)
	{
		string ss;
		cin>>ss;
		ans+=ma[ss];
	}
	cout<<ans<<endl;

	return 0;
}