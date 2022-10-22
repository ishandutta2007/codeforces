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

const int Maxn = 100005;

int n;
int a[Maxn];
ll sum;
map <ll, int> A, B;

void Insert(map <ll, int> &M, ll x) { M[x]++; }

void Remove(map <ll, int> &M, ll x)
{
	if (--M[x] == 0) M.erase(x);
}

bool Is(map <ll, int> &M, ll x) { return M.find(x) != M.end(); }

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]); sum += a[i];
  	}
  	if (sum % 2) { printf("NO\n"); return 0; }
  	sum /= 2;
  	for (int i = 0; i < n; i++)
  		Insert(B, a[i]);
  	ll cur = 0;
  	for (int i = 0; i <= n; i++) {
  		if (0 < i && i < n && cur == sum) { printf("YES\n"); return 0; }
  		if (1 < i && Is(A, cur - sum)) { printf("YES\n"); return 0; }
  		if (i < n - 1 && Is(B, sum - cur)) { printf("YES\n"); return 0; }
  		if (i < n) {
  			Insert(A, a[i]); Remove(B, a[i]);
  			cur += a[i];
  		}
  	}
  	printf("NO\n");
	return 0;
}