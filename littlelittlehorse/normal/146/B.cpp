#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a[11], len;
char str[101];

bool check(int now){
	len = 0;
	for (; now; now /= 10) a[++len] = now % 10;
	int value = 0;
	for (int i = len; i; --i)
		if (a[i] == 4 || a[i] == 7) value = value * 10 + a[i];
	return value == m;
}

int main(){
	scanf("%d%d", &n, &m);
	if (n < m)
	{
		printf("%d\n", m);
		return 0;
	}
	for (int i = n + 1; ; i++)
		if (check(i)) 
		{
			printf("%d\n", i);
			return 0;
		}
}