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

const int Maxn = 200005;

char tmp[Maxn];
string t, p;
int a[Maxn];
bool tk[Maxn];

bool Check(int x)
{
	for (int i = 0; i < x; i++)
		tk[a[i]] = true;
	int cur = 0;
	for (int i = 0; i < t.length(); i++) if (!tk[i])
		if (cur < p.length() && t[i] == p[cur]) cur++;
	for (int i = 0; i < x; i++)
		tk[a[i]] = false;
	return cur == p.length();
}

int main() 
{
	scanf("%s", tmp); t = tmp;
	scanf("%s", tmp); p = tmp;
	for (int i = 0; i < t.length(); i++) {
		scanf("%d", &a[i]); a[i]--;
	}
	int lef = 1, rig = t.length();
	int res = 0;
	while (lef <= rig) {
		int mid = lef + rig >> 1;
		if (Check(mid)) { res = mid; lef = mid + 1; }
		else rig = mid - 1;
	}
	printf("%d\n", res);
    return 0;
}