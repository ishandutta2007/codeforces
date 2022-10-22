#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxm = 1000005;
const ll mod = 1000000007;

bool prime[Maxm];
vector <int> pr;
ll n, k;

ll phi(ll n)
{
	if (n == 1) return 1;
	ll sum = n;
	for (int i = 0; i < pr.size() && pr[i] <= n / pr[i]; i++)
		if (n % pr[i] == 0) {
			sum -= sum / pr[i];
			while (n % pr[i] == 0) n /= pr[i];
		}
	if (n > 1) sum -= sum / n;
	return sum;
}

int main() 
{
	fill(prime + 2, prime + Maxm, true);
	for (int i = 2; i < Maxm; i++) if (prime[i]) {
		pr.push_back(i);
		for (int j = i + i; j < Maxm; j += i) prime[j] = false;
	}
	scanf("%I64d %I64d", &n, &k);
	n = phi(n);
	for (ll cur = 3; cur <= k && n > 1; cur += 2)
		n = phi(n);
	n %= mod;
	cout << n << endl;
    return 0;
}