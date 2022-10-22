#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 5005;
const int mod = 1000000007;

int n;
int ways[Maxn];

int main()
{
	scanf("%d", &n);
	ways[0] = 1;
	char lst = 'f';
	for (int i = 0; i < n; i++) {
		char ch; scanf(" %c", &ch);
		int cur = 0, my;
		for (int j = Maxn - 2; j >= 0; j--) {
			cur = (cur + ways[j]) % mod; my = ways[j]; ways[j] = 0;
			if (ch == 'f') 
				if (lst == 's') ways[j + 1] = (ways[j + 1] + cur) % mod;
				else ways[j + 1] = (ways[j + 1] + my) % mod;
			else if (ch == 's') 
					if (lst == 's') ways[j] = (ways[j] + cur) % mod;
					else ways[j] = (ways[j] + my) % mod;
		}
		lst = ch;
	}
	if (lst == 'f') { printf("0\n"); return 0; }
	int res = 0;
	for (int i = 0; i < Maxn; i++)
		res = (res + ways[i]) % mod;
	printf("%d\n", res);
	return 0;
}