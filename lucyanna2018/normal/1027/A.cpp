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
int n;
char s[111];
bool chk(char x, char y) {
	if(x>y)swap(x,y);
	if(x=='a')return y=='a'||y=='c';
	if(y=='z')return x=='z'||x=='x';
	int xx = x - 'a', yy = y - 'a';
	int z = (xx - yy + 26) % 26;
	return z == 0 || z == 2 || z == 24;
}
bool chk() {
	for (int i = 0, j = n - 1; i <= j; i++, j--)
		if (!chk(s[i], s[j]))
			return false;
	return true;
}
int main() {
	int _;
	for (scanf("%d", &_); _--;) {
		scanf("%d%s", &n, s);
		puts(chk() ? "YES" : "NO");
	}
	return 0;
}