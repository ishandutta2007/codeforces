#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int n,ok;
int A[20];

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

void Work()
{
	sort(A + 1, A + n + 1);
	int ans = 0;
	for(int i = 1; i <= 1e8; i ++) ans = ans * rand();
	for(int i = 1; i <= n; i ++) printf("%d ", A[i]);
}

void Init()
{
	n = read();
	for(int i = 1; i <= n; i ++)
		A[i] = read();
}

int main(){
	Init();
	Work();
	return 0;
}