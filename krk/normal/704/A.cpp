#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

const int Maxn = 300005;

int n, q;
deque <int> has[Maxn];
int seq[Maxn], slen;
int unr;
int mx;

int main()
{
	scanf("%d %d", &n, &q);
	while (q--) {
		int typ; scanf("%d", &typ);
		if (typ == 1) {
			int x; scanf("%d", &x);
			seq[slen++] = x;
			has[x].push_back(slen); unr++;
		} else if (typ == 2) {
			int x; scanf("%d", &x);
			unr -= has[x].size(); has[x].clear();
		} else {
			int t; scanf("%d", &t);
			while (mx < t) {
				int ind = seq[mx];
				if (has[ind].size() > 0 && has[ind][0] == mx + 1) {
					has[ind].pop_front(); unr--;
				}
				mx++;
			}
		}
		printf("%d\n", unr);
	}
	return 0;
}