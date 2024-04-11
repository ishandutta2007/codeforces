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

int n,cnt[300];
char s[300];
queue<int> q;
int main() {
	scanf("%d%s",&n,s+1);
	if (n%4!=0) {
		puts("===");
		return 0;
	}
	for (int i=1;i<=n;i++) {
		if (s[i]!='?') cnt[s[i]-0]++;
	}
	if (cnt['A']>n/4 || cnt['G']>n/4 || cnt['C']>n/4 || cnt['T']>n/4) {
		puts("===");
		return 0;
	}
	for (int i=1;i<=n/4-cnt['A'];i++) q.push('A');
	for (int i=1;i<=n/4-cnt['G'];i++) q.push('G');
	for (int i=1;i<=n/4-cnt['T'];i++) q.push('T');
	for (int i=1;i<=n/4-cnt['C'];i++) q.push('C');
	for (int i=1;i<=n;i++) {
		if (s[i]!='?') putchar(s[i]);
		else {putchar(q.front());q.pop();}
	}
	return 0;
}