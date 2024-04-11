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

const int Maxn = 5005;

char tmp[Maxn];
int n, m;
string val[Maxn];
int ida[Maxn], idb[Maxn];
int op[Maxn];
map <string, int> ID;
int res[Maxn];
string ans1, ans2;

int Get(int ind)
{
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		if (ind < val[i].size()) 
			res[i] = val[i][ind] == '1';
		else 
			if (op[i] == 0) res[i] = (res[ida[i]] & res[idb[i]]);
			else if (op[i] == 1) res[i] = (res[ida[i]] ^ res[idb[i]]);
			else if (op[i] == 2) res[i] = (res[ida[i]] | res[idb[i]]);
		tot += res[i];
	}
	return tot;
}

int main() 
{
	scanf("%d %d", &n, &m);
	ID["?"] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%s", tmp); string s = tmp; ID[s] = i;
		scanf("%s", tmp);
		scanf("%s", tmp);
		if (tmp[0] == '0' || tmp[0] == '1') val[i] = tmp;
		else {
			string a = tmp;
			scanf("%s", tmp); 
			if (tmp[0] == 'A') op[i] = 0;
			else if (tmp[0] == 'X') op[i] = 1;
			else op[i] = 2;
			scanf("%s", tmp); string b = tmp;
			ida[i] = ID[a], idb[i] = ID[b];
		}
	}
	ans1 = string(m, '0'); ans2 = string(m, '1');
	for (int i = 0; i < m; i++) {
		res[0] = 0;
		int r1 = Get(i);
		res[0] = 1;
		int r2 = Get(i);
		ans1[i] = r1 <= r2? '0': '1';
		ans2[i] = r1 >= r2? '0': '1';
	}
	printf("%s\n", ans1.c_str());
	printf("%s\n", ans2.c_str());
    return 0;
}