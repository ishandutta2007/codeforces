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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B;
	cin >> A >> B;
	vi X(A), Y(A);
	B--;

	REP(i, A) cin >> X[i];
	REP(i, A) cin >> Y[i];

	vector<bool> seen(A);
	seen[0] = true;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i = 0; i < A; i++) {
			if (i < cur && !seen[i] && Y[i] && Y[cur]) { // use the Y
				seen[i] = true;
				q.push(i);
			}
			if (i > cur && !seen[i] && X[i] && X[cur]) { // use the X
				seen[i] = true;
				q.push(i);
			}
		}
	}

	cout << (seen[B] ? "YES" :"NO")<<endl;
	return 0;
}