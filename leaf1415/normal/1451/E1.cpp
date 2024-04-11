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

ll n;
ll a[1<<17];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	ll a12, x12;
	cout << "AND" << " " << 1 << " " << 2 << endl;
	cin >> a12;
	cout << "XOR" << " " << 1 << " " << 2 << endl;
	cin >> x12;
	
	ll a23, x23;
	cout << "AND" << " " << 2 << " " << 3 << endl;
	cin >> a23;
	cout << "XOR" << " " << 2 << " " << 3 << endl;
	cin >> x23;
	
	ll a13;
	cout << "AND" << " " << 1 << " " << 3 << endl;
	cin >> a13;
	
	rep(i, 0, 15){
		if(a12&(1<<i)){
			a[1] |= (1<<i);
			continue;
		}
		if((x12&(1<<i)) == 0) continue;
		
		if((x23&(1<<i))){
			if(a13&(1<<i)) a[1] |= 1<<i;
		}
		else{
			if((a23&(1<<i)) == 0) a[1] |= 1<<i;
		}
	}
	a[2] = a[1] ^ x12;
	a[3] = a[2] ^ x23;
	
	ll res;
	rep(i, 4, n){
		cout << "XOR" << " " << 1 << " " << i << endl;
		cin >> res;
		a[i] = a[1] ^ res;
	}
	
	cout << "! ";
	rep(i, 1, n) cout << a[i] << " "; cout << endl;
	
	return 0;
}