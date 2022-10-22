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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size(); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n;
string s, t;
deque<char> deq, deq2;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s >> t;
	n = s.size();
	sort(all(s)), sort(all(t)), reverse(all(t));
	
	rep(i, 1, (n+1)/2) deq.push_back(s[i-1]);
	rep(i, 1, n/2) deq2.push_back(t[i-1]);
	
	string head, tail;
	rep(i, 0, n-1){
		if(i % 2 == 0){
			if(deq.front() >= deq2.front()) tail += deq.back(), deq.pop_back();
			else head += deq.front(), deq.pop_front();
		}
		else{
			if(deq.front() >= deq2.front()) tail += deq2.back(), deq2.pop_back();
			else head += deq2.front(), deq2.pop_front();
		}
	}
	reverse(all(tail));
	cout << head + tail << endl;
	
	return 0;
}