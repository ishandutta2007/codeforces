#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
char str[101];

int main(){
	//freopen("a.in", "r", stdin);
	scanf("%d", &n);
	scanf("%s", str); 
	bool ok = true;
	for (int i = 0; i < n && ok; i++)
		if (str[i] != '4' && str[i] != '7') ok = false;
	if (ok)
	{
		int sum = 0;
		for (int i = 1; i <= n / 2; i++)
			sum += str[i - 1] - '0', sum -= str[n - i] - '0';
		if (sum) ok = false;
	}
	if (ok) printf("YES\n");
	else printf("NO\n");
}