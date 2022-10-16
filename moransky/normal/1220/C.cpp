// Skyqwq
#include <iostream>
#include <cstdio>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

const int N = 5e5 + 5;

char s[N];

int main() {
	scanf("%s", s + 1);
	int mn = 2e9;
	for (int i = 1; s[i]; i++) {
		if (mn < s[i] - 'a') puts("Ann");
		else puts("Mike");
		mn = min(mn, s[i] - 'a');
	}
	return 0;
}