#include<bits/stdc++.h>
using namespace std;
int n;
int sum=0;
int a[3][1000000];
int main() {
	int q,r,c;
	scanf("%d %d",&n,&q);
	while(q--) {
		scanf("%d %d",&r,&c);
		if(a[r][c]==1) {
			if(a[3-r][c-1]==1) sum--;
			if(a[3-r][c]==1) sum--;
			if(a[3-r][c+1]==1) sum--;
			a[r][c]=0;
		}
		else {
			if(a[3-r][c-1]==1) sum++;
			if(a[3-r][c]==1) sum++;
			if(a[3-r][c+1]==1) sum++;
			a[r][c]=1;
		}
		if(sum==0) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}