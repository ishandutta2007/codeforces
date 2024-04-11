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

vector <int> V;

int n, L;
set <vector <int> > S;

int main() 
{
	scanf("%d %d", &n, &L);
	vector <int> cur;
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		cur.push_back(a);
	}
	S.insert(cur);
	for (int i = 1; i < L; i++) {
		vector <int> tmp;
		for (int j = 0; j < cur.size(); j++)
			tmp.push_back((cur[j] - i + L) % L);
		sort(tmp.begin(), tmp.end());
		S.insert(tmp);
	}
	cur.clear();
	for (int i = 0; i < n; i++) {
		int b; scanf("%d", &b);
		cur.push_back(b);
	}
	printf("%s\n", S.find(cur) != S.end()? "YES": "NO");
    return 0;
}