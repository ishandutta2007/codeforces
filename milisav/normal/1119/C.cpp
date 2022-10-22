#include<bits/stdc++.h>
int n,m;
int a[600][600];
int b[600][600];
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) scanf("%d",&a[i][j]);
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) scanf("%d",&b[i][j]);
	}
	for(int i=0;i<n;i++) {
		int c1=0,c2=0;
		for(int j=0;j<m;j++) {
			if(a[i][j]==1) c1++;
			if(b[i][j]==1) c2++;
		}
		if((c2&1)!=(c1&1)) {
			printf("No");
			return 0;
		}
	}
	for(int j=0;j<m;j++) {
		int c1=0,c2=0;
		for(int i=0;i<n;i++) {
			if(a[i][j]==1) c1++;
			if(b[i][j]==1) c2++;
		}
		if((c2&1)!=(c1&1)) {
			printf("No");
			return 0;
		}
	}
	printf("Yes");
	return 0;
}