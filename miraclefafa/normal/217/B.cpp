#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>
using namespace std;
int n,r,ans,k,i,t,res,v;
int ck(int a,int b) {
	if (b==0 && a!=1) return 100000000;
	if (b==1 && a==1) {
		return 1;
	} else if (b==1) {
		res+=a-2;
		return a;
	}
	res+=a/b-1;
	return ck(b,a%b)+a/b;
}
void pt(int a,int b) {
	if (b==1) {
		printf("T");
		for (int i=0;i<a-1;i++) printf("B");
		return;
	}
	pt(b,a%b);
	if (v) for (int i=0;i<a/b;i++) printf("B"); else for (int i=0;i<a/b;i++) printf("T");
	v=1-v;
}
int main() {
	scanf("%d%d",&n,&r);
	if (n==1 && r==1) {printf("0\nT\n");return 0;}
	ans=-1;k=0;
	for (int i=1;i<r;i++) {
		res=0;int t=ck(r,i);
		if (t==n) if (ans==-1 || res<ans) ans=res,k=i;
	}
	if (ans==-1) puts("IMPOSSIBLE"); else {
		printf("%d\n",ans);
		v=0;pt(r,k);puts("");
	}
}