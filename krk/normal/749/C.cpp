#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;

int n;
char str[200005];
set <ll> R, D;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char ch; scanf(" %c", &ch);
		if (ch == 'R') R.insert(i);
		else D.insert(i);
	}
	while (!R.empty() && !D.empty())
		if (*R.begin() < *D.begin()) {
			ll x = *R.begin();
			R.erase(R.begin()); D.erase(D.begin());
			R.insert(x + n);
		} else {
			ll x = *D.begin();
			R.erase(R.begin()); D.erase(D.begin());
			D.insert(x + n);
		}
	if (!R.empty()) printf("R\n");
	else printf("D\n");
	return 0;
}