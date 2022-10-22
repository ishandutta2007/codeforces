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

llint T;
llint a, b, q;
llint sum[40005];

llint get(llint x)
{
	llint ret = x/(a*b)*sum[a*b];
	ret += sum[x%(a*b)];
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> a >> b >> q;
		if(a > b) swap(a, b);
		
		sum[0] = 0;
		for(int i = 1; i <= a*b; i++){
			sum[i] = sum[i-1];
			if(i%a%b != i%b%a) sum[i]++;
		}
		
		llint l, r;
		for(int i = 0; i < q; i++){
			cin >> l >> r;
			cout << get(r)-get(l-1) << " ";
		}
		cout << endl;
	}
	
	return 0;
}