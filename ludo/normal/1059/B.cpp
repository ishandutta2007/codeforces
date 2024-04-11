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

const int maxn = 1000;

int N, M;
bool A[maxn][maxn], B[maxn][maxn] = {};

bool canplace(int a, int b)
{
	return A[a-1][b-1] && A[a-1][b] && A[a-1][b+1] && A[a][b-1] && A[a][b+1] && A[a+1][b-1] && A[a+1][b] && A[a+1][b+1];
}

void place(int a, int b)
{
	B[a-1][b-1]=B[a-1][b] =B[a-1][b+1]=B[a][b-1]=B[a][b+1]=B[a+1][b-1]=B[a+1][b] =B[a+1][b+1] = true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	REP(i, N) {
		string S;
		cin >> S;
		REP(j, M)
			A[i][j] = S[j] == '#';
	}

	for (int i = 1; i + 1 < N; i++) {
		for (int j = 1; j + 1 < M; j++) {
			if (canplace(i, j))
				place(i, j);
		}
	}

	REP(i, N) REP(j, M) if (A[i][j] != B[i][j]) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	return 0;
}