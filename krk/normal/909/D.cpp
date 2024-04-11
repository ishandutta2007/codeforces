#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef pair <char, int> ci;

const int Maxn = 1000005;

char str[Maxn];
int slen;
list <ci> L;
int res;

int main()
{
	scanf("%s", str); slen = strlen(str);
	for (int i = 0, j; i < slen; i = j) {
		j = i;
		while (j < slen && str[i] == str[j]) j++;
		L.push_back(ci(str[i], j - i));
	}
	int len = L.size();
	while (len > 1) {
		res++;
		L.begin()->second++;
		L.rbegin()->second++;
		for (list <ci>::iterator it = L.begin(); it != L.end(); ) {
			it->second -= 2;
			if (it->second <= 0) { L.erase(it++); len--; }
			else it++;
		}
		if (len == 0) break;
		list <ci>::iterator it1 = L.begin(), it2 = L.begin();
		it2++;
		while (it1 != L.end()) {
			while (it2 != L.end() && it1->first == it2->first) {
				it1->second += it2->second; L.erase(it2++); len--;
			}
			it1++;
			if (it2 != L.end()) it2++;
		}
	}
	printf("%d\n", res);
	return 0;
}