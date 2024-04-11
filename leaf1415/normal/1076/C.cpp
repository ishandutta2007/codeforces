#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;

llint T;
llint d;

int main(void)
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> d;
		if(d*d - 4*d < 0){
			cout << "N" << endl;
			continue;
		}
		
		double D = sqrt(d*d-4*d);
		double a = d + D, b = d - D;
		a /= 2, b /= 2;
		printf("Y %.11f %.11f\n", a, b);
	}
	
	return 0;
}