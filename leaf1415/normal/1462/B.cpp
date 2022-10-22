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
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll Q;
ll n;
string s, t;
string S = "2020", T = "0202";

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	while(Q--){
		cin >> n;
		cin >> s;
		t = s;
		reverse(all(t));
		
		rep(i, 0, 4){
			if(s.substr(0, i) == S.substr(0, i) && t.substr(0, 4-i) == T.substr(0, 4-i)){
				cout << "YES" << endl;
				goto end;
			}
		}
		cout << "NO" << endl;
		end:;
	}
	
	return 0;
}