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

const int Maxn = 1005;

map <string, vector <int> > M;
map <string, int> C;
int n;
string a[Maxn], b[Maxn], res[Maxn];
bool done[Maxn];

int main() 
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		M[a[i].substr(0, 3)].push_back(i);
	}
	for (map <string, vector <int> >::iterator it = M.begin(); it != M.end(); it++)
		if (it->second.size() > 1)
			for (int i = 0; i < it->second.size(); i++) {
				int ind = it->second[i];
				string nw = a[ind].substr(0, 2) + b[ind].substr(0, 1);
				C[nw]++; res[ind] = nw; done[ind] = true;
			}
	bool loop = true;
	while (loop) {
		loop = false;
		for (map <string, vector <int> >::iterator it = M.begin(); it != M.end(); it++)
			if (it->second.size() == 1) if (!done[it->second[0]]) {
				int ind = it->second[0];
				if (C.find(a[ind].substr(0, 3)) != C.end()) {
					string nw = a[ind].substr(0, 2) + b[ind].substr(0, 1);
					C[nw]++; res[ind] = nw; done[ind] = true;
					loop = true;
				}
			}
	}
	for (map <string, vector <int> >::iterator it = M.begin(); it != M.end(); it++)
		if (it->second.size() == 1) if (!done[it->second[0]]) {
			int ind = it->second[0];
			string nw = a[ind].substr(0, 3);
			C[nw]++; res[ind] = nw; done[ind] = true;
		}
	for (map <string, int>::iterator it = C.begin(); it != C.end(); it++)
		if (it->second > 1) { printf("NO\n"); return 0; }
	printf("YES\n");
	for (int i = 0; i < n; i++)
		printf("%s\n", res[i].c_str());
    return 0;
}