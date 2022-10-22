#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;

int n;
int a[Maxn];
int Lmn[Maxn], Rmn[Maxn];
int Lmx[Maxn], Rmx[Maxn];
ll res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	vector <int> A, B;
	for (int i = 0; i < n; i++) {
		while (!A.empty() && a[A.back()] <= a[i]) {
			Rmx[A.back()] = i - 1;
			A.pop_back();
		}
		Lmx[i] = A.empty()? 0: A.back() + 1;
		A.push_back(i);
		while (!B.empty() && a[B.back()] >= a[i]) {
			Rmn[B.back()] = i - 1;
			B.pop_back();
		}
		Lmn[i] = B.empty()? 0: B.back() + 1;
		B.push_back(i);
	}
	while (!A.empty()) {
		Rmx[A.back()] = n - 1;
		A.pop_back();
	}
	while (!B.empty()) {
		Rmn[B.back()] = n - 1;
		B.pop_back();
	}
	for (int i = 0; i < n; i++) {
		ll cnt = ll(Rmx[i] - i + 1) * (i - Lmx[i] + 1) - ll(Rmn[i] - i + 1) * (i - Lmn[i] + 1);
		res += cnt * a[i];
	}
	printf("%I64d\n", res);
	return 0;
}