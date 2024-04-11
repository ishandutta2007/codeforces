#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> pii;
typedef long long LL;
#define N 1011

int hidden[N] = {0, 1, 3, 5, 2, 4, 6, 7};

int n, K, key = 3;
map <int, int> cnt;

pii Q(vector <int> a) {
	printf("?");
	for (auto v : a) {
		printf(" %d", v);
	}
	printf("\n");
	fflush(stdout);
/*	vector <pii> test;
	for (auto v : a) {
		test.push_back({hidden[v], v});
	}
	sort(test.begin(), test.end());
	printf("%d %d\n", test[key - 1].second, test[key - 1].first);
	return test[key - 1];*/
	int xx, yy;
	scanf("%d%d", &xx, &yy);
	return {yy, xx};
}


int main() {
	cin >> n >> K;
//	cin >> key;
	if (K == 1) {
		puts("! 1");
		fflush(stdout);
		return 0;
	}
	vector <int> qry;
	for (int i = 1; i <= K; i++) {
		qry.push_back(i);
	}
	pii a1 = Q(qry);
	qry.clear();
//	cerr << a1.first << " " << a1.second << "!!\n";
	for (int i = 1; i <= K + 1; i++) {
		if (i != a1.second) qry.push_back(i);
	}
	pii a2 = Q(qry);
	cnt[a1.second]++;
	cnt[a2.second]++;
	for (int i = 1; i <= K + 1; i++) {
		if (i == a1.second) continue;
		if (i == a2.second) continue;
		qry.clear();
		for (int j = 1; j <= K + 1; j++) {
			if (i == a1.second);
			else if (i == a2.second);
			else if (i == j) continue;
			qry.push_back(j);
		}
		cnt[Q(qry).second]++;
	}
	printf("! %d\n", K - cnt[a1 > a2 ? a2.second : a1.second] + 1);
}