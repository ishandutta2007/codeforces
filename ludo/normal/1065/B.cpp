#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

ll min_needed(ll x) {
	return (x + 1) / 2;
}

ll max_needed(ll x) {
	return x * (x - 1) / 2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll N, M;
	cin >> N >> M;

	ll maxnconn = 0;
	while (maxnconn < N && min_needed(maxnconn + 1) <= M) maxnconn++;
	ll minnconn = N;
	while (minnconn > 0 && max_needed(minnconn - 1) >= M) minnconn--;

	cout << (N - maxnconn) << " " << (N - minnconn) << endl;

	return 0;
}