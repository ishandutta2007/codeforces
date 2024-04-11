/*
#Drazil and Factorial
F(x)xF(132)=1!*3!*2!=12anF(n)=F(a)n01
a<=15
 http://codeforces.com/problemset/problem/515/C

kan'0'-'9'a
a



4
1234

33222
*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 20;

int n;
char str[MAXN], ans[MAXN * 4];

int main(){
	int i, j;
	scanf("%d%s", &n, str + 1);
	for(i = 1, j = 0; i <= n; ++ i)
		switch(str[i]){
			case '4':
				ans[++ j] = '3';
				ans[++ j] = '2';
				ans[++ j] = '2';
				break;
			case '6':
				ans[++ j] = '3';
				ans[++ j] = '5';
				break;
			case '8':
				ans[++ j] = '2';
				ans[++ j] = '2';
				ans[++ j] = '2';
				ans[++ j] = '7';
				break;
			case '9':
				ans[++ j] = '2';
				ans[++ j] = '3';
				ans[++ j] = '3';
				ans[++ j] = '7';
				break;
			default:
				if(str[i] != '0' && str[i] != '1') ans[++ j] = str[i];
				break;
		}
	sort(ans + 1, ans + 1 + j);
	for(; j; -- j) putchar(ans[j]);
	putchar('\n');
	return 0;
}