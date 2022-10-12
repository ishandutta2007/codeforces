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
int n, m;
char s[99999];int ls;
int main(){
	scanf("%d", &n);
	for (int L = (n - 1) / 9; L--;) {
		s[ls++] = '9';
		s[ls++] = '0';
	}
	s[ls++] = '9';
	s[ls++] = '1';
	puts(s);
	s[ls - 1] = 0;
	puts(s);
	return 0;
}