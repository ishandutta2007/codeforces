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
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;
typedef pair<llint, P> E;

llint n;
vector<P> vec;

void calc(llint l, llint r)
{
	llint L = r-l+1, mul = 1;
	for(;mul < L; mul*=2){
		for(int i = 0; i < L; i++){
			if((i & mul) == 0) vec.push_back(P(l+i, l+mul+i));
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	llint b;
	for(b = 1; b*2 <= n; b *= 2);
	
	calc(1, b);
	if(b < n) calc(n-b+1, n);
	
	cout << vec.size() << endl;
	for(int i = 0; i < vec.size(); i++){
		cout << vec[i].first << " " << vec[i].second << "\n";
	}
	flush(cout);
	
	
	return 0;
}