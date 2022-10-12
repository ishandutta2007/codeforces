#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
#define ran 111111
int n;long long int a[4];
char s1[ran], s2[ran];
int main() {
	scanf("%d%s%s", &n,s1,s2);
	for (int i = 0; i < n; i++)a[(s1[i] - '0') * 2 + (s2[i] - '0')]++;
	long long int res = a[0] * a[2] + a[0] * a[3] + a[1] * a[2];
	cout << res << endl;
	return 0;
}