/*	Never stop fighting for what you believe in.	*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;

#define MAXN 100005

int n,m;
int d[MAXN],a[MAXN],last[MAXN];

struct exam {
	int last,x;
	bool operator < (exam aa) const {
		return last<aa.last;
	}
}e[MAXN];

bool check(int mid) {
	memset(last,-1,sizeof(last));
	for (int i=1;i<=mid;i++) {
		if (d[i]) last[d[i]]=i;
	}
	for (int i=1;i<=m;i++) {
		if (last[i]==-1) return 0;
		e[i].last=last[i];
		e[i].x=i;
	}
	sort(e+1,e+m+1);
	int now=0;
	for (int i=1;i<=m;i++) {
		int nowx=e[i].x;
		if (last[nowx]<=now+a[nowx]) return 0;
		now+=a[nowx]+1;
	}
	return 1;
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) {
		scanf("%d",d+i);
	}
	for (int i=1;i<=m;i++) {
		scanf("%d",a+i);
	}
	int l=m,r=n+1,mid;
	while (l<r) {
		mid=(l+r)>>1;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	if (l>n) puts("-1");
	else printf("%d\n",l);
	return 0;
}