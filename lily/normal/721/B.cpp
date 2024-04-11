#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;
/* Configuration */
#define MAXN 105
string dir[MAXN],pas;
int n,k;

inline bool cmp(string a,string b) {
	return a.size()<b.size();
}

int main() {
	cin>>n>>k;
	for (int i=1;i<=n;i++) {
		cin>>dir[i];
	}
	cin>>pas;
	int pl=pas.size(),ans1=0,ans2=0;
	sort(dir+1,dir+n+1,cmp);
	for (int i=1;i<=n;i++) {
		int len=dir[i].size();
		if (len==pl && !ans1)
			ans1=i;
		if (len>pl) {
			ans2=i-1;
			break;
		}
	}
	if (!ans2) ans2=n;
	int tt=((ans1-1)/k)*5+ans1;
	printf("%d ",tt);
	tt=((ans2-1)/k)*5+ans2;
	printf("%d\n",tt);
	return 0;
}