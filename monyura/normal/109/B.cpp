#pragma comment(linker,"/STACK:60777216")
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
typedef long double ld;
typedef pair<int,int> pii;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}

ll peresek(int a,int b,int fr,int to)
{
	if (a>fr)
	{
		swap(a,fr);
		swap(b,to);
	}
	if (b<fr) return 0;
	if (b>=to) return to-fr+1;
	return b-fr+1;
}

int main()
{
	int pl,pr;
	int vl,vr;
	int k;
	cin>>pl>>pr;
	cin>>vl>>vr;
	cin>>k;

	vector<ll> vec;
	rep(l,1,10)
	{
		rep(i,0,1<<l)
		{
			ll ten=1;
			ll curr=0;
			rep(j,0,l)
			{
				curr=curr+(((i>>j)&1) ? 4:7)*ten;
				ten*=10;
			}
			if (curr<=1000000000LL)
				vec.push_back(curr);
		}
	}
	vec.push_back(0);
	vec.push_back(1000000001LL);
	sort(all(vec));
	ll cnt=0;
	rep(i,1,vec.size()-k)
	{
		cnt+=peresek(vec[i-1]+1,vec[i],pl,pr)*peresek(vec[i+k-1],vec[i+k]-1,vl,vr);
		cnt+=peresek(vec[i-1]+1,vec[i],vl,vr)*peresek(vec[i+k-1],vec[i+k]-1,pl,pr);
		if (k==1 && pl<=vec[i] && pr>=vec[i] && vl<=vec[i] && vr>=vec[i])
		{
			cnt--;
		}
	}
	printf("%.10lf\n",double(cnt)/double(ll(vr-vl+1)*ll(pr-pl+1)));
	return 0;
}
/*
1 1 777777777 777777777 1022
3 4 4 5 1
*/