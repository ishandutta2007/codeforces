#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
string s;
int n, k;
bool f[222222];
int main() {
	cin >> n >> k >> s;
	k /= 2;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			f[i] = true;
			++cnt;
			if (cnt == k)break;
		}
	}
	cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == ')') {
			f[i] = true;
			++cnt;
			if (cnt == k)break;
		}
	}
	for (int i = 0; i < n; i++)if (f[i])putchar(s[i]);
	puts("");
	return 0;
}