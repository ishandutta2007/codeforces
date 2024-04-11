#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int a[1005];
int n,h;
vector <int> vec;

int main()
{
//	freopen("input.txt","r",stdin);
	int n,h;
	cin>>n>>h;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int put=0;put<=n;put++)
	{
		vec.clear();
		for(int i=0;i<put;i++)
		{
			vec.push_back(a[i]);
		}
		sort(all(vec));
		reverse(all(vec));
		int th=h;
//		if(put==3)
//		{
//			cout<<vec[0]<<' '<<vec[2]<<endl;
//		}
		for(int i=0;i<vec.size();i+=2)
		{
			th-=vec[i];
		}
		if(th<0)
		{
			cout<<put-1<<endl;
			return 0;
		}
	}
	cout<<n<<endl;
	return 0;
}