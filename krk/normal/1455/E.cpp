#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const ll Inf = 1000000000000000000ll;
const int Maxd = 4;

int T;
ii p[Maxd];

int main()
{
	scanf("%d", &T);
	while (T--) {
		vector <int> seq;
		for (int i = 0; i < Maxd; i++)
			scanf("%d %d", &p[i].first, &p[i].second);
		for (int i = 0; i < Maxd; i++)
			for (int j = i + 1; j < Maxd; j++) {
				seq.push_back(abs(p[i].first - p[j].first));
				seq.push_back(abs(p[i].second - p[j].second));
			}
		vector <int> V;
		for (int i = 0; i < Maxd; i++)
			V.push_back(i);
		ll res = Inf;
		do {
			for (int j = 0; j < seq.size(); j++) {
				ll cand = 0;
				vector <ll> X, Y;
				X.push_back(p[V[0]].first);
				X.push_back(p[V[2]].first);
				X.push_back(p[V[1]].first - seq[j]);
				X.push_back(p[V[3]].first - seq[j]);
				Y.push_back(p[V[0]].second);
				Y.push_back(p[V[1]].second);
				Y.push_back(p[V[2]].second - seq[j]);
				Y.push_back(p[V[3]].second - seq[j]);
				sort(X.begin(), X.end());
				sort(Y.begin(), Y.end());
				for (int a = 0; a < Maxd; a++)
					cand += ll(abs(X[a] - X[1])) + ll(abs(Y[a] - Y[1]));
				res = min(res, cand);
			}
		} while (next_permutation(V.begin(), V.end()));
		printf("%I64d\n", res);
	}
    return 0;
}