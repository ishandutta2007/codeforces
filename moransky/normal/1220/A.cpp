// Skyqwq
#include <iostream>
#include <cstdio>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

const int N = 1e5 + 5;

int n, cnt[200];

char s[N];

int main() {
	scanf("%d%s", &n, s + 1);
	for (int i = 1; i <= n; i++) cnt[s[i]]++;
	for (int i = 0; i <= cnt['o']; i++) {
		int A = cnt['z'], B = cnt['e'] - i, C = cnt['r'], D = cnt['o'] - i;
		if (A == B && B == C && C == D) {
			for (int j = 1; j <= i; j++) printf("1 ");
			for (int j = 1; j <= A; j++) printf("0 ");
			return 0;
		}
	}
	return 0;
}