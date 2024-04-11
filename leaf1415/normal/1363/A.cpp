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
llint n, x;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> x;
		llint a, odd = 0, even = 0;
		for(int i = 1; i <= n; i++){
			cin >> a;
			if(a%2) odd++;
			else even++;
		}
		for(int i = 0; i <= min(x, odd); i++){
			if(i%2 && x-i <= even){
				cout << "Yes" << endl;
				goto end;
			}
		}
		cout << "No" << endl;
		end:;
	}
	return 0;
}