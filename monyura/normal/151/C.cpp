#pragma comment(linker,"/STACK:128000000")
#include <cstdio>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <complex>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <functional>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef short int si;
typedef unsigned short int usi;
typedef long double ld;
typedef pair<int,int> pii;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define x first
#define y second

const double PI=acos(-1.0);

map<ll,int> mp;

//ll dyn(ll a)
//{
//	if (mp.find(a)!=mp.end()) return mp[a];
//	bool mex[200]={0};
//	bool pr=1;
//	for (ll j=2;j*j<=a;j++)
//		if (a%j==0)
//		{
//			pr=0;
//			mex[dyn(j)]=1;
//			mex[dyn(a/j)]=1;
//		}
//	if (pr) return mp[a]=1;
//	rep(i,0,200)
//		if (!mex[i])
//			return mp[a]=i;
//}

int main()
{
	ll a;
	cin>>a;
	vector<int> v;
	for (ll j=2;j*j<=a;j++)
			while (a%j==0)
			{
				v.push_back(j);
				a/=j;
			}
	if (a!=1) v.push_back(a);
	if (v.size()==2) printf("2\n");
	else 
	{
		if (v.size()<=1) printf("1\n0\n");
		else
		{
			printf("1\n");
			cout<<v[0]*v[1]<<endl;
		}
	}
	return 0;
} 

/*
10000000000000

*/