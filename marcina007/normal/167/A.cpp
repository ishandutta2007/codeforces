#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <sstream>
using namespace std;
#define PB push_back
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FORE(i,x) for(__typeof((x).begin()) i=(x).begin();i != (x).end();++i)
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,w) memset((x),w,sizeof (x))
#define X first
#define Y second
typedef long long int lli;
typedef pair<int, int> P;
typedef vector<int> VI;

int n;
double a,d,t,v,last=0,t0,d0,res;

int main(){ 
	scanf("%d%lf%lf", &n, &a, &d);
	while(n--){
		scanf("%lf%lf", &t, &v);
		t0 = v / a;
		d0 = a * t0 * t0 / 2;
		if(d0 >= d)
			res = t + sqrt(2 * d / a);
		else
			res = t + t0 + (d - d0) / v;
		res = max(res, last);
		printf("%.8lf\n", res);
		last = res;
	}
    return 0;
}