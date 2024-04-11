#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int A[200];
int C[200];
int B[200];

int n;

int solve0(bool print){
	for (int i = 0; i < n; ++i)
		C[i] = A[i];

	int ans = 0;
	for (int i = 0; i < n; ++i){
		while (C[i]){
			ans++;
			for (int j = 0; j < n; ++j){
				if (abs(j - i) <= 1){
					C[j] = max(C[j] - 1, 0);
					if (print)
						putchar('1');
				}
				else{
					if (print)
					putchar('0');
				}
			}
			if (print)
			putchar('\n');
		}
	}
	return ans;
}

void print(vector<pii> P, vector<pii> Q, pii r, int t){
	int p = 0, q = 0;

	for (int i = 0; i < t; ++i){
		bool up = false, uq = false;
		for (int j = 0; j < n; ++j){
			bool ok = false;

			if (j == r.second && r.first){
				r.first--;
				ok = true;
			}

			if (!up && P[p].second == j){
				up = true;
				P[p].first--;
				if (P[p].first == 0) ++p;
				ok = true;
			}

			if (!uq && Q[q].second == j){
				uq = true;
				Q[q].first--;
				if (Q[q].first == 0) ++q;
				ok = true;
			}

			if (ok) putchar('1');
			else putchar('0');
		}
		putchar('\n');
	}
}

int main(){
	scanf("%d", &n);

	int m = 100;

	for (int i = 0; i < n; ++i){
		scanf("%d", &A[i]);
		m = min(m, A[i]);
	}

	int R = 0;

	for (int j = m; j >= 0; --j){
		int M = 0;
		int S = 0;

		for (int i = 0; i < n; ++i){
			B[i] = max(A[i] - j, 0);
			S += B[i];
			M = max(M, B[i]);
		}

		if (2 * M <= S){
			R = j;
			break;
		}
	}

	if (R == 0){
		printf("0\n%d\n", solve0(false));
		solve0(true);
	}
	else{
		int p = 0, q = 0;
		vector<pii> P, Q, U, T;
		for (int i = 0; i < n; ++i)
			if (B[i]) T.push_back({B[i], i});

		sort(T.begin(), T.end());
		reverse(T.begin(), T.end());

		for (auto t : T){
			if (p <= q){
				P.push_back(t);
				p += t.first;
			}
			else{
				Q.push_back(t);
				q += t.first;
			}
		}

		if (p > q){
			P.back().first -= p - q;
			U.push_back({p - q, P.back().second});

			int d = p - q;
			p -= d;
		}

		if (q > p){
			Q.back().first -= q - p;
			U.push_back({q - p, Q.back().second});
			int d = q - p;
			q -= d;
		}

		pii val = U.empty() ? pii(0, 0) : U[0];

		printf("%d\n%d\n", R, p);
		print(P, Q, val, p);
	}

	return 0;
}