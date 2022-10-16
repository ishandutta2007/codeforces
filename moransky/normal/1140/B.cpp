#include <cstdio>
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 110;
int n;
char s[N];
int main(){
	int T; scanf("%d", &T);
	while(T--){
		scanf("%d%s", &n, s + 1);
		int l = 1, r = n;
		while(s[l] != '>') l++;
		while(s[r] != '<') r--;
		printf("%d\n", min(l - 1, n - r));
	}
	return 0;
}