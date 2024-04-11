#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxl = 100005;

int k, n;
char str[Maxl];
string s;
map <string, vector <int> > A, B, S;
int add;
int res;

void Read(string &s)
{
	scanf("%s", str); s = str;
}

int main()
{
	scanf("%d %d", &k, &n);
	for (int i = 0; i < k; i++) {
		Read(s); int num; scanf("%d", &num);
		string tmp = s;
		reverse(tmp.begin(), tmp.end());
		if (s == tmp) S[s].push_back(num);
		else if (s < tmp) A[s].push_back(num);
		else B[tmp].push_back(num);
	}
	for (map <string, vector <int> >::iterator it = S.begin(); it != S.end(); it++) {
		sort(it->second.rbegin(), it->second.rend());
		int pnt = 0;
		while (pnt + 2 <= it->second.size() && it->second[pnt + 1] > 0) {
			res += it->second[pnt] + it->second[pnt + 1]; pnt += 2;
		}
		if (pnt == it->second.size()) continue;
		if (pnt + 1 == it->second.size() || it->second[pnt] + it->second[pnt + 1] < 0) add = max(add, it->second[pnt]);
		else { res += it->second[pnt] + it->second[pnt + 1]; add = max(add, -it->second[pnt + 1]); }
	}
	for (map <string, vector <int> >::iterator it = A.begin(); it != A.end(); it++) {
		map <string, vector <int> >::iterator it2 = B.find(it->first);
		if (it2 == B.end()) continue;
		sort(it->second.rbegin(), it->second.rend());
		sort(it2->second.rbegin(), it2->second.rend());
		for (int i = 0; i < it->second.size() && i < it2->second.size() && it->second[i] + it2->second[i] > 0; i++)
			res += it->second[i] + it2->second[i];
	}
	res += add;
	printf("%d\n", res);
	return 0;
}