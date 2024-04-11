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
using namespace std;

const int Maxn = 5005;

string s;
int res;
bool L[Maxn][Maxn], R[Maxn][Maxn];

int main()
{
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		int st = 0;
		int mn = 0;
		int cur = 0;
		for (int j = i; j < s.length(); j++) {
			if (s[j] == '?') cur++;
			else if (s[j] == ')') {
				st--;
				if (st < mn) { 
					mn = st;
					if (cur < -mn) break;
				}
			} else if (s[j] == '(') st++;
			L[i][j] = true;
		}
	}
	for (int i = int(s.length()) - 1; i >= 0; i--) {
		int st = 0;
		int mn = 0;
		int cur = 0;
		for (int j = i; j >= 0; j--) {
			if (s[j] == '?') cur++;
			else if (s[j] == '(') {
				st--;
				if (st < mn) {
					mn = st;
					if (cur < -mn) break;
				}
			} else if (s[j] == ')') st++;
			R[j][i] = true;
		}
	}
	for (int i = 0; i < s.length(); i++)
		for (int j = i + 1; j < s.length(); j += 2)
			if (L[i][j] && R[i][j]) res++;
	printf("%d\n", res);
	return 0;
}