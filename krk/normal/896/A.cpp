#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const ll Inf = 4000000000000000000ll;
const int Maxn = 100005;

const string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
const string p1 = "What are you doing while sending \"";
const string p2 = "\"? Are you busy? Will you send \"";
const string p3 = "\"?";

ll len[Maxn];
int q;
int n;
ll k;

char Get(int n, ll k)
{
	if (n == 0) return k < len[0]? f0[k]: '.';
	if (k < ll(p1.length())) return p1[k];
	k -= ll(p1.length());
	if (k < len[n - 1]) return Get(n - 1, k);
	k -= len[n - 1];
	if (k < ll(p2.length())) return p2[k];
	k -= ll(p2.length());
	if (k < len[n - 1]) return Get(n - 1, k);
	k -= len[n - 1];
	if (k < ll(p3.length())) return p3[k];
	return '.';
}

int main()
{
	len[0] = f0.length();
	for (int i = 1; i < Maxn; i++)
		len[i] = min(Inf, ll(p1.length()) + len[i - 1] + ll(p2.length()) + len[i - 1] + ll(p3.length()));
	scanf("%d", &q);
	while (q--) {
		scanf("%d %lld", &n, &k); k--;
		printf("%c", Get(n, k));
	}
	printf("\n");
	return 0;
}