#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int k, q;
	cin >> k >> q;

	vector<pii> query(q);

	for (int i = 0; i < q; ++i){
		cin >> query[i].first;
		query[i].second = i;
	}

	sort(query.begin(), query.end());
	vector<int> answer(q);

	vector<double> prob(k + 1);
	prob[1] = 1;
	int pnt = 0;

	for (int d = 1; pnt < q; ++d){
		while (pnt < q && prob[k] * 2000 >= 1.0 * query[pnt].first){
			answer[ query[pnt].second ] = d;
			pnt++;
		}

		if (pnt == q) break;

		vector<double> nprob(k + 1);

		for (int i = 0; i <= k; ++i)
			nprob[i] = prob[i] * i / k + prob[i - 1] * (k - (i - 1)) / k;

		prob.swap(nprob);
	}

	for (int i = 0; i < q; ++i)
		cout << answer[i] << endl;

	return 0;
}