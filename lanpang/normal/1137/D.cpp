#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int get()
{
	int ret;
	scanf("%d",&ret);
	char c;
	do{
		c = getchar();
	}while (c != '\n');
	return ret;
}

int main()
{
	int i , j;
	do{
		printf("next 0\n");
		fflush(stdout);
		i = get();
		printf("next 0 1\n");
		fflush(stdout);
		i = get();
	}while (i != 2);
	do{
		printf("next 0 1 2 3 4 5 6 7 8 9\n");
		fflush(stdout);
		i = get();
	}while (i != 1);
	printf("done\n");
	fflush(stdout);
	return 0;
}