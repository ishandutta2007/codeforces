#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
char s[1010000],fg;int n;
int main() {
	scanf("%s",s);
	n=strlen(s);
	fg=1;
	for (int i=0;i<n;i++) fg&=(s[i]=='1');
	if (fg) rep(i,0,n-1) putchar('1');
	else {
		fg=0;
		rep(i,0,n) {
			if (fg||s[i]=='1') putchar(s[i]); else fg=1;
		}
	}
}