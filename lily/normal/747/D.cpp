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
struct range {
	int st,ed;
	range(){}
	range(int a,int b):st(a),ed(b){}
	bool operator < (range a) const {
		return ed-st<a.ed-a.st;
	}
}r[MAXN],can;
int n,k,K=0;
int ans=0,flag=0;

int main() {
	scanf("%d%d",&n,&k);
	K=k;
	int nowst=0,top=0;
	for (int i=1,x;i<=n;i++) {
		scanf("%d",&x);
		if (x>=0) x=0;
		else x=1,k--; 
		if (x!=nowst) {
			if (!x) {
				r[++top].st=i;
			}
			else {
				r[top].ed=i;
			}
		}
		nowst=x;
	}
	if (k<0) {
		puts("-1");
		return 0;
	}
	if (k==K) {
		puts("0");
		return 0;
	}
	if (nowst==0) {
		can=r[top];
		can.ed=n+1;
		top--;
	}
	sort(r+1,r+top+1);
	int cnt=0,nowans=top*2+1+(nowst==0);
	for (int i=1;i<=top;i++) {
		if (cnt+r[i].ed-r[i].st<=k) cnt+=r[i].ed-r[i].st,nowans-=2;
	}
	ans=nowans;
	if (nowst==0 && can.ed-can.st<=k) {
		cnt=can.ed-can.st;
		nowans=top*2+1;
		for (int i=1;i<=top;i++) {
			if (cnt+r[i].ed-r[i].st<=k) cnt+=r[i].ed-r[i].st,nowans-=2;
		}
		ans=min(ans,nowans);
	}
	printf("%d\n",ans);
	return 0;
}