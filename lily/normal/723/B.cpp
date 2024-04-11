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



#define MAXN 300

int n;
char s[MAXN];


int main() {
	scanf("%d%s",&n,s+1);
	bool ink=0;
	bool aword=0;
	int len=0,maxlen=0,cnt=0;
	for (int i=1;i<=n;i++) {
		if ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) {
			if (aword) {
				len++;
			}
			else {
				aword=1;
				len=1;
			}
		}
		else {
			if (aword) {
				if (ink) {
					cnt++;
				}
				else {
					if (len>maxlen) {
						maxlen=len;
					}
				}
				aword=0;
				len=0;
			}
			if (s[i]=='(') {
				ink=1;
			}
			else if (s[i]==')') {
				ink=0;
			}
		}
	}
	if (aword) {
		if (len>maxlen) {
			maxlen=len;
		}
	}
	printf("%d %d\n",maxlen,cnt);
	return 0;
}