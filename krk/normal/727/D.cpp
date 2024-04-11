#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxd = 6;
const string nams[Maxd] = {"S", "M", "L", "XL", "XXL", "XXXL"};

map <string, int> ID;
int freq[Maxd];
int n;
vector <ii> need[Maxd];
int has[Maxn];

int main()
{
	ID["S"] = 0;
	ID["M"] = 1;
	ID["L"] = 2;
	ID["XL"] = 3;
	ID["XXL"] = 4;
	ID["XXXL"] = 5;
	for (int i = 0; i < Maxd; i++)
		scanf("%d", &freq[i]);
	char tmp[50];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		has[i] = -1;
		scanf("%s", tmp);
		string s = tmp;
		int ind = s.find(',');
		if (ind == string::npos) {
			int ind = ID[s];
			if (freq[ind] <= 0) { printf("NO\n"); return 0; }
			freq[ind]--; has[i] = ind;
		} else {
			string a = s.substr(0, ind), b = s.substr(ind + 1);
			int ida = ID[a], idb = ID[b];
			if (ida > idb) swap(ida, idb);
			need[ida].push_back(ii(0, i)); need[idb].push_back(ii(1, i));
		}
	}
	for (int i = 0; i < Maxd; i++) {
		sort(need[i].begin(), need[i].end());
		while (freq[i] > 0 && !need[i].empty()) {
			int ind = need[i].back().second; need[i].pop_back();
			if (has[ind] == -1) { freq[i]--; has[ind] = i; }
		}
	}
	for (int i = 0; i < n; i++)
		if (has[i] == -1) { printf("NO\n"); return 0; }
	printf("YES\n");
	for (int i = 0; i < n; i++)
		printf("%s\n", nams[has[i]].c_str());
	return 0;
}