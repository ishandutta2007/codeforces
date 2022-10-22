#include<bits/stdc++.h>
using namespace std;
int n,q;
int a[400000];
int t[300005][20];
int c[20];
int m=20;
int main()
{
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<m;i++) {
		t[n][i]=c[i]=n;
	}
	for(int i=n-1;i>=0;i--) {
		for(int j=0;j<m;j++) t[i][j]=n;
		for(int j=0;j<m;j++) {
			if(a[i]&(1<<j)) {
				t[i][j]=i;
				for(int k=0;k<m;k++) t[i][k]=min(t[i][k],t[c[j]][k]);
				c[j]=i; 
			}
		}
	}
	int x,y;
	while(q--) {
		scanf("%d %d",&x,&y);
		x--;
		y--;
		bool p=false;
		for(int j=0;j<m && !p;j++) if((a[y]&(1<<j)) && t[x][j]<y) p=true;
		if(p) printf("Shi\n");
		else printf("Fou\n");
	}
	
	return 0;
}