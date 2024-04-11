#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;
/* Configuration */


int n,top=0,st=0;
char s[105];
int cnt[105];

int main() {
	scanf("%d%s",&n,s+1);
	for (int i=1;i<=n;i++) {
		if (s[i]=='B') {
			if (st==1) {
				cnt[top]++;
			}
			else {
				st=1;
				cnt[++top]=1;
			}
		}
		else {
			if (st==1) {
				st=0;
			}
		}
	}
	printf("%d\n",top);
	for (int i=1;i<=top;i++) printf("%d ",cnt[i]);


	return 0;
}