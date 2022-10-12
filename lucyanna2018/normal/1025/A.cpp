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

int n;char s[111111];int cnt[26];
int main() {
	scanf("%d%s", &n, s);
	for (int i = 0; i < n; i++)cnt[s[i]-'a'] ++;
	bool flag = (n == 1);
	for (int i = 0; i < 26; i++)if (cnt[i] >= 2)flag = true;
	puts(flag ? "Yes" : "No");
	return 0;
}