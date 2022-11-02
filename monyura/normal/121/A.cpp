#pragma comment(linker,"/STACK:32000000")
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
typedef short int si;
typedef unsigned short int usi;
typedef long double ld;
typedef pair<int,int> pii;
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}

vector<int> vec;

void rec(int step,int val)
{
	if (step>=9) return;
	vec.push_back(val);
	rec(step+1,val*10+4);
	rec(step+1,val*10+7);
}

int main()
{
	int l,r;
	cin>>l>>r;
	rec(0,4);
	rec(0,7);
	int curr=l;
	vec.push_back(-1);
	sort(all(vec));
	ll res=0;
	int i=1;
	for (i=1;i<vec.size();i++)
	{
		if (vec[i]>=l && vec[i]<=r)
			res+=ll(vec[i])*(vec[i]-max(l-1,vec[i-1]));
		if (vec[i]>r) break;
	}
	ll last=4444444444LL;
	if (i!=vec.size())
		last=vec[i];
	if (vec[i-1]<r)
		res+=last*(r-max(l-1,vec[i-1]));
	cout<<res<<endl;
	return 0;
}
/*
1
84
*/