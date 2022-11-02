#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, a[100001];

int read(){
	char ch;
	for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar());
	int cnt = 0;
	for (; ch >= '0' && ch <= '9'; ch = getchar())
		cnt = cnt * 10 + ch - '0';
	return cnt;
}

int main(){
	n = read();
	for (int i = 1; i <= n; i++)
	{
		int x = read(), y = read();
		a[x] = y;
	}
	int Max = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] < Max) 
		{
			printf("Happy Alex\n");
			return 0;
		}
		Max = max(Max, a[i]);
	}
	printf("Poor Alex\n");
}