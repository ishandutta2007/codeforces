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

ll a[15], b[15];
string l, r;

bool check()
{
	//rep(i, 0, 9) cout << a[i] << " "; cout << endl;
	rep(i, l[0]-'0'+1, r[0]-'0'-1) if(a[i]) return true;
	
	rep(i, 0, 9) b[i] = a[i];
	if(b[l[0]-'0']){
		b[l[0]-'0']--;
		rep(j, 1, (int)l.size()-1){
			rep(k, l[j]-'0'+1,  9) if(b[k]) return true;
			if(b[l[j]-'0'] == 0) goto end; 
			b[l[j]-'0']--;
		}
		return true;
		end:;
	}
	
	rep(i, 0, 9) b[i] = a[i];
	if(b[r[0]-'0']){
		b[r[0]-'0']--;
		rep(j, 1, (int)r.size()-1){
			rep(k, 0, r[j]-'0'-1) if(b[k]) return true;
			if(b[r[j]-'0'] == 0) goto end2;
			b[r[j]-'0']--;
		}
		return true;
		end2:;
	}
	
	return false;
}

ll calc(ll n, ll d)
{
	if(n == 0){
		if(check()) return 1;
		else return 0;
	}
	
	ll ret = 0;
	a[d]++;
	ret += calc(n-1, d);
	a[d]--;
	
	if(d+1 <= 9) ret += calc(n, d+1);
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> l >> r;
	if(l == r){
		cout << 1 << endl;
		return 0;
	}
	
	while(l.size() < 19) l.insert(l.begin(), '0');
	while(r.size() < 19) r.insert(r.begin(), '0');
	
	ll p = 0;
	rep(i, 0, 18) if(l[i] != r[i]){
		p = i;
		break;
	}
	l = l.substr(p), r = r.substr(p);
	
	cout << calc(l.size(), 0) << endl;
	
	return 0;
}