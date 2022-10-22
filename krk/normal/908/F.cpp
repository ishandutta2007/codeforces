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

typedef long long ll;

const int Maxn = 300005;

int n;
int p[Maxn];
char ch[Maxn];
ll res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %c", &p[i], &ch[i]);
	int lst = -1;
	for (int i = 0; i < n; i++)
		if (ch[i] == 'R' || ch[i] == 'G') {
			if (lst != -1) res += p[i] - lst;
			lst = p[i];
		}
	lst = -1;
	for (int i = 0; i < n; i++)
		if (ch[i] == 'B' || ch[i] == 'G') {
			if (lst != -1) res += p[i] - lst;
			lst = p[i];
		}
	int lstg = -1;
	int firr = -1, lstr = -1, mxr = 0;
	int firb = -1, lstb = -1, mxb = 0;
	for (int i = 0; i < n; i++)
		if (ch[i] == 'G') {
			if (lstr != -1) mxr = max(mxr, p[i] - lstr);
			if (lstb != -1) mxb = max(mxb, p[i] - lstb);
			if (lstg != -1) {
				if (lstr != -1 && lstb != -1) {
					ll way1 = -ll(mxr) - ll(mxb) + ll(p[i] - lstg);
					res += min(way1, 0ll);
				} else {
					res += p[i] - lstg;
					if (lstr != -1) res -= mxr;
					else res -= (p[i] - lstg);
					if (lstb != -1) res -= mxb;
					else res -= (p[i] - lstg);
				}
			}
			lstg = p[i];
			firr = -1, lstr = -1; mxr = 0;
			firb = -1, lstb = -1; mxb = 0;
		} else if (ch[i] == 'R') {
			if (lstr != -1) mxr = max(mxr, p[i] - lstr);
			else { 
				firr = p[i]; 
				if (lstg != -1) mxr = max(mxr, p[i] - lstg); 
			}
			lstr = p[i];
		} else if (ch[i] == 'B') {
			if (lstb != -1) mxb = max(mxb, p[i] - lstb);
			else {
				firb = p[i];
				if (lstg != -1) mxb = max(mxb, p[i] - lstg);
			}
			lstb = p[i];
		}
	printf("%I64d\n", res);
	return 0;
}