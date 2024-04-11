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

const int Maxd = 10;

int n;
string a, b;
int freq[Maxd], tk[Maxd];

bool Get(int dig)
{
	while (dig >= 0 && tk[dig] >= freq[dig]) dig--;
	if (dig >= 0) { tk[dig]++; return true; }
	return false;
}

int main() 
{
	scanf("%d", &n);
	cin >> a >> b;
	for (int i = 0; i < n; i++)
		freq[a[i] - '0']++;
	int res1 = 0, res2 = 0;
	for (int i = 0; i < n; i++)
		if (!Get(b[i] - '0')) res1++;
	fill(tk, tk + Maxd, 0);
	for (int i = 0; i < n; i++)
		if (Get(b[i] - '0' - 1)) res2++;
	printf("%d\n%d\n", res1, res2);
    return 0;
}