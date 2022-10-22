#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n, m;
vector <int> negA, posA;
vector <int> negB, posB;
int my[Maxn];

int Solve(vector <int> &A, vector <int> &B)
{
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	my[A.size()] = 0;
	for (int i = int(A.size()) - 1; i >= 0; i--) {
		int ind = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
		if (ind < B.size() && B[ind] == A[i]) my[i] = 1;
		else my[i] = 0;
		my[i] += my[i + 1]; 
	}
	int res = 0;
	int pos = 0;
	for (int i = 0; i < B.size(); i++) {
		while (pos < A.size() && B[i] + pos >= A[pos]) pos++;
		int got = lower_bound(B.begin(), B.end(), B[i] + pos) - lower_bound(B.begin(), B.end(), B[i]);
		res = max(res, got + my[pos]);
	}
	return res;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		negA.clear(); posA.clear();
		negB.clear(); posB.clear();
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			if (a > 0) posA.push_back(a);
			else negA.push_back(-a);
		} 
		for (int i = 0; i < m; i++) {
			int a; scanf("%d", &a);
			if (a > 0) posB.push_back(a);
			else negB.push_back(-a);
		}
		printf("%d\n", Solve(negA, negB) + Solve(posA, posB));
	}
    return 0;
}