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

const int Maxn = 100005;

char str[Maxn];
string a, b;
int L[Maxn];
int R[Maxn];

void Read(string &s)
{
	scanf("%s", str); s = str;
}

int main() 
{
	Read(a); Read(b);
	int pnt = 0;
	for (int i = 0; i < b.length(); i++) {
		while (pnt < a.length() && a[pnt] != b[i]) pnt++;
		L[i] = pnt++;
	}
	int cur = 0;
	for (int i = a.length() - 1; i >= 0; i--) {
		if (cur < b.length() && a[i] == b[int(b.length()) - 1 - cur]) cur++;
		R[i] = cur;
	}
	int res = R[0], bi = -1;
	for (int i = 0; i < b.length(); i++) if (L[i] < a.length()) {
		int cand = min(int(b.length()), i + 1 + R[L[i] + 1]);
		if (cand > res) { res = cand; bi = i; }
	}
	if (res == 0) printf("-\n");
	else {
		int lef = bi + 1, rig = (bi == -1)? R[0]: R[L[bi] + 1];
		for (int i = 0; i < lef; i++)
			printf("%c", b[i]);
		for (int i = b.length() - rig; i < b.length(); i++)
			printf("%c", b[i]);
		printf("\n");
	}
    return 0;
}