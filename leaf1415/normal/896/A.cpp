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
typedef long long ll;
typedef pair<llint, llint> P;

ll Q;
ll len[100005];
string s = "What are you doing at the end of the world? Are you busy? Will you save us?";
string t[] = {
	"What are you doing while sending \"",
	"\"? Are you busy? Will you send \"",
	"\"?"
};

char calc(ll n, ll k)
{
	if(k >= len[n]) return '.';
	if(n == 0) return s[k];

	if(k < t[0].size()) return t[0][k];
	k -= t[0].size();

	if(k < len[n-1]) return calc(n-1, k);
	k -= len[n-1];

	if(k < t[1].size()) return t[1][k];
	k -= t[1].size();

	if(k < len[n-1]) return calc(n-1, k);
	k -= len[n-1];

	if(k < t[2].size()) return t[2][k];
	k -= t[2].size();

	return '.';
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	len[0] = s.size();
	rep(i, 1, 100000){
		len[i] = t[0].size() + t[1].size() + t[2].size() + 2 * len[i-1];
		chmin(len[i], (ll)1e18 + 10);
	}

	cin >> Q;
	ll n, k;
	rep(i, 1, Q){
		cin >> n >> k;
		k--;
		cout << calc(n, k);
	}
	cout << endl;

	return 0;
}