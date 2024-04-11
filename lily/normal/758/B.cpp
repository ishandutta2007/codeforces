/* Never Say Die. */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;


string s;
int cnt[256], kind[4];


void mark(char a, int p) {
	kind[p] = a;
}


int main() {
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; i++) if (s[i] != '!') mark(s[i], i % 4);
	for (int i = 0; i < len; i++) {
		if (s[i] == '!') cnt[kind[i % 4]]++;
	}
	printf("%d %d %d %d\n", cnt['R'], cnt['B'], cnt['Y'], cnt['G']);
	return 0;
}