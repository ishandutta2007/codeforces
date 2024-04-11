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
#include <stack>
using namespace std;
typedef pair<int,int> pii;
#define MAXN 1000005

struct edge {
	int next;
	pii to;
}e[MAXN*2];

int head[MAXN],tot[MAXN],ecnt=0,top=0,len,p=1;
char s[MAXN];

void add(int x,pii to) {
	e[++ecnt].to=to;
	e[ecnt].next=head[x];
	head[x]=ecnt;
}

pii getWord() {
	while (s[p]==',') p++;
	int st=p;
	while (s[p]!=',') p++;
	return make_pair(st,p-1);
}
int getLen() {
	while (s[p]==',') p++;
	int ret=0;
	while (s[p]>='0' && s[p]<='9') {ret=ret*10+s[p]-'0';p++;}
	return ret;
}

void dfs(int depth) {
	if (depth>top) top=depth;
	pii hh=getWord();
	add(depth,hh);
	int num=getLen();
	for (int i=1;i<=num;i++) {
		dfs(depth+1);
	}
}

void output(pii hh) {
	int st=hh.first,ed=hh.second;
	for (int i=st;i<=ed;i++) putchar(s[i]);
	putchar(' ');
}

stack <pii> sta;

int main() {
	scanf("%s",s+1);
	len=strlen(s+1);
	while (p<=len) dfs(0);
	printf("%d\n",top+1);
	for (int i=0;i<=top;i++) {
		for (int now=head[i];now;now=e[now].next) {
			sta.push(e[now].to);
		}
		while (!sta.empty()) {
			output(sta.top());sta.pop();
		}
		putchar('\n');
	}
	return 0;
}