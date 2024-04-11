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



long long a[5],ans,temp[5],top=0;


int main() {
	cin>>a[1]>>a[2]>>a[3];
	long long MIN=min(min(a[1],a[2]),a[3]);
	int cnt=0;
	for (int i=1;i<=3;i++) {
		a[i]-=MIN;
		if (a[i]>0) cnt++;
	}
	if (cnt==0) puts("0");
	else if (cnt==1) {
		for (int i=1;i<=3;i++) {
			if (a[i]>0) {
				ans=max(0ll,(a[i]-1)*2);
			}
		}
		cout<<ans<<endl;
	}
	else {
		for (int i=1;i<=3;i++) {
			if (a[i]>0) {
				temp[++top]=a[i];
			}
		}
		if (temp[1]<temp[2]) swap(temp[1],temp[2]);
		if (temp[1]==temp[2]) {
			ans=max(0ll,temp[1]-1);
		}
		else {
			ans=max(0ll,(temp[1]-temp[2]-1)+(temp[1]-1));
		}
		cout<<ans<<endl;
	}
	return 0;
}