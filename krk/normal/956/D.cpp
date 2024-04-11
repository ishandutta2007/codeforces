#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ii, ii> iiii;
typedef pair <ii, int> iii;

const int Maxn = 100005;

int n, w;
int X[Maxn], V[Maxn];
int BIT[Maxn];
ll res;

bool Less(const ii &a, const ii &b)
{
	return ll(a.first) * b.second < ll(b.first) * a.second;
}

bool Equal(const ii &a, const ii &b)
{
	return ll(a.first) * b.second == ll(b.first) * a.second;
}

bool More(const ii &a, const ii &b)
{
	return ll(a.first) * b.second > ll(b.first) * a.second;
}

bool Comp(const iiii &a, const iiii &b)
{
	if (!Equal(a.first, b.first)) return Less(a.first, b.first);
	return More(a.second, b.second);
}

bool Comp2(const iii &a, const iii &b)
{
	if (!Equal(a.first, b.first)) return Less(a.first, b.first);
	return a.second > b.second;
}

int Get(int x)
{
	x++;
	int res = 0;
	for (int i = x; i < Maxn; i += i & -i)
		res += BIT[i];
	return res;
}

void Add(int x)
{
	x++;
	for (int i = x; i > 0; i -= i & -i)
		BIT[i]++;
}

void Solve(const vector <ii> &V)
{
	fill(BIT, BIT + Maxn, 0);
	vector <iiii> seq;
	for (int i = 0; i < V.size(); i++)
		seq.push_back(iiii(ii(V[i].first, V[i].second + w), ii(V[i].first, V[i].second - w)));
	sort(seq.begin(), seq.end(), Comp);
	vector <iii> un;
	for (int i = 0; i < seq.size(); i++)
		un.push_back(iii(seq[i].second, i));
	sort(un.begin(), un.end(), Comp2);
	for (int i = 0; i < un.size(); i++) {
		res += Get(un[i].second);
		Add(un[i].second);
	}
}

ll Count(const vector <ii> &A, const vector <ii> &B)
{
	ll res = 0;
	int i = 0;
	for (int j = 0; j < B.size(); j++) {
		while (i < A.size() && Less(A[i], B[j])) i++;
		res += i;
	}
	return res;
}

ll Both()
{
	vector <ii> A1, A2, B1, B2;
	for (int i = 0; i < n; i++)
		if (X[i] < 0) {
			A1.push_back(ii(-X[i], V[i] + w));
			A2.push_back(ii(-X[i], V[i] - w));
		} else {
			B1.push_back(ii(X[i], -V[i] + w));
			B2.push_back(ii(X[i], -V[i] - w));
		}
	sort(A1.begin(), A1.end(), Less); sort(A2.begin(), A2.end(), Less);
	sort(B1.begin(), B1.end(), Less); sort(B2.begin(), B2.end(), Less);
	return ll(A1.size()) * ll(B1.size()) - Count(A2, B1) - Count(B2, A1);
}

int main()
{
	scanf("%d %d", &n, &w);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &X[i], &V[i]);
	vector <ii> tosolve;
	for (int i = 0; i < n; i++)
		if (X[i] > 0) tosolve.push_back(ii(X[i], -V[i]));
	Solve(tosolve);
	tosolve.clear();
	for (int i = 0; i < n; i++)
		if (X[i] < 0) tosolve.push_back(ii(-X[i], V[i]));
	Solve(tosolve);
	res += Both();
	cout << res << endl;
	return 0;
}