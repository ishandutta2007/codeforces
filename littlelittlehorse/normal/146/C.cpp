#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a[11], len;
char str1[100001], str2[100001];

int main(){
	int cnt1 = 0, cnt2 = 0;
	scanf("%s", str1); scanf("%s", str2);
	n = strlen(str1);
	for (int i = 0; i < n; i++)
		if (str1[i] == '4' && str2[i] == '7') ++cnt1;
		else 
		if (str1[i] == '7' && str2[i] == '4') ++cnt2;
	printf("%d\n", max(cnt1, cnt2));
}