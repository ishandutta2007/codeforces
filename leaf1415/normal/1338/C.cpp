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
llint n;
set<llint> S;
llint c[] = {0, 2, 3, 1}, c2[] = {0, 3, 1, 2};

P get(llint l)
{
	l++;
	llint mul = 1, ret = 0;
	while(l > mul){
		l -= mul;
		mul *= 4;
	}
	return P(mul, l-1);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	//T = 100;
	for(int t = 0; t < T; t++){
		cin >> n;
		//n = t+1;
		n--;
		
		llint l = n/3, p = n % 3;
		P res = get(l);
		llint g = res.first, offset = res.second;
		
		//cout <<g << " " << offset << endl;
		
		if(p == 0){
			cout << g + offset << "\n";
			continue;
		}
		llint ans = g, rem = offset;
		if(p == 1){
			ans *= 2;
			for(llint d = g/4; d; d/=4){
				ans += c[rem/d] * d;
				rem %= d;
			}
		}
		if(p == 2){
			ans *= 3;
			for(llint d = g/4; d; d/=4){
				ans += c2[rem/d] * d;
				rem %= d;
			}
		}
		cout << ans << "\n";
	}
	flush(cout);
	
	/*for(int i = 1; i <= 100; i++){
		llint a, b, c;
		for(int j = 1; ; j++){
			if(S.count(j)) continue;
			a = j;
			S.insert(a);
			break;
		}
		for(int j = a+1; ; j++){
			if(S.count(j) || S.count(j^a)) continue;
			b = j, c = j^a;
			S.insert(b), S.insert(c);
			break;
		}
		cout << a << " " << b << " " << c << endl;
	}*/
	
	return 0;
}