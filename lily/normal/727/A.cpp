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
struct statu {
	long long x;
	int rec;
	statu(){}
	statu(long long q,int b):x(q),rec(b){}
}ans;


long long a,b;


queue <statu> q;
bool flag=0;
int sta[1000],top;
int main() {
	cin>>a>>b;
	q.push(statu(a,1));
	while (!q.empty()) {
		statu now=q.front();q.pop();
		if (now.x==b) {flag=1,ans=now;break;}
		if (now.x<<1 <= b) q.push(statu(now.x<<1,now.rec<<1));
		if (now.x*10+1<=b) q.push(statu(now.x*10+1,(now.rec<<1)^1));
	}
	if (flag) {
		printf("YES\n");
		int st=ans.rec,x=(int)b;
		top=0;
		while (st>1) {
			sta[++top]=x;
			if (st&1) {
				x=(x-1)/10;
			}
			else {
				x/=2;
			}
			st>>=1;
		}
		printf("%d\n%d",top+1,(int)a);
		for (int i=top;i>0;i--) printf(" %d",sta[i]);
	}
	else puts("NO");
	return 0;
}