/*	Never stop fighting for what you believe in.	*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;


#define MAXN 100005
char s[MAXN];
long long money=0,fuck=0;

void check(int st,int ed) {
	int len=ed-st+1;
	if (len<3) {
		long long ff=0;
		for (int i=st;i<=ed;i++) {
			if (s[i]!='.') ff=ff*10+s[i]-'0';
		}
		money+=ff;
	}
	else if (s[ed-2]=='.') {
		fuck+=(s[ed-1]-'0')*10+s[ed]-'0';
		if (fuck>=100) {
			money+=fuck/100;
			fuck%=100;
		}
		check(st,ed-2);
	}
	else {
		long long ff=0;
		for (int i=st;i<=ed;i++) {
			if (s[i]!='.') ff=ff*10+s[i]-'0';
		}
		money+=ff;
	}
}

char sta[200];
int top=0,len;

int main() {
	scanf("%s",s+1);
	len=(int)strlen(s+1);
	for (int i=1;i<=len;i++) {
		if (s[i]=='.'||(s[i]>='0'&&s[i]<='9')) {
			int j;
			for (j=i+1;j<=len;j++) {
				if (s[j]=='.'||(s[j]>='0'&&s[j]<='9')) continue;
				else break;
			}
			j--;
			check(i,j);
			i=j;
		}
	}
	if (fuck) {
		sta[++top]=fuck%10+'0';
		sta[++top]=fuck/10+'0';
		sta[++top]='.';
		if (!money) sta[++top]='0';
	}
	int cnt=0;
	while (money) {
		sta[++top]=money%10+'0';
		money/=10;
		cnt++;
		if (cnt==3) {
			cnt=0;
			if (money) {
				sta[++top]='.';
			}
		}
	}
	while (top) {
		putchar(sta[top--]);
	}
	return 0;
}