#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

const int Maxn = 50005;

int n;
int a[Maxn];
set <int> S;
vector <int> res;

int Get(int num)
{
	while (S.find(num) != S.end())
		num /= 2;
	return num;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		S.insert(a[i]);
	}
	while (true) {
		int num = *S.rbegin();
		int nw = Get(num);
		if (nw == 0) break;
		S.erase(num); S.insert(nw);
	}
	for (set <int>::iterator it = S.begin(); it != S.end(); it++)
		printf("%d ", *it);
	printf("\n");
	return 0;
}