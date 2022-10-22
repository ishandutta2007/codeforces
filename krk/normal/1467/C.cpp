#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a, b, c;
vector <ll> A, B, C;
ll suma, sumb, sumc;
ll res;

void Read(vector <ll> &V, ll &sum, int n)
{
	for (int i = 0; i < n; i++) {
		int num; scanf("%d", &num);
		V.push_back(num);
		sum += num;
	}
	sort(V.begin(), V.end());
}

int main()
{
	scanf("%d %d %d", &a, &b, &c);
	Read(A, suma, a);
	Read(B, sumb, b);
	Read(C, sumc, c);
	ll mn = min(min(suma, sumb), sumc);
	mn = min(mn, A[0] + B[0] + C[0] - max(max(A[0], B[0]), C[0]));
	cout << suma + sumb + sumc - 2 * mn << endl;
    return 0;
}