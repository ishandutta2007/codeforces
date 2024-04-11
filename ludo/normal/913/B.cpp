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

const int MAXN = 1e3;

bool isl[MAXN] = {};
int p[MAXN], nc[MAXN] = {};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> p[i];
		p[i]--;
	}

	fill_n(isl, N, true);
	for (int i = N; --i; ) isl[p[i]] = false;

	for (int i = N; --i; )
		if (isl[i]) nc[p[i]]++;

	bool spruce = true;
	for (int i = N; --i >= 0; ) {
		if (!isl[i] && nc[i] < 3) spruce = false;
	}


	cout << (spruce ? "YES" : "NO") << endl;
	return 0;
}