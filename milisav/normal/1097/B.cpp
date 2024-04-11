#include<bits/stdc++.h>
using namespace std;
int p[360];
int r[360];
int a[20];
int main()
{
	p[0]=1;
	int n;
	int t;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++) {
		for(int j=0;j<360;j++) r[j]=0;
		for(int j=0;j<360;j++) {
			t=j+a[i];
			if(t>=360) t-=360;
			r[j]+=p[t];
			t=j-a[i];
			if(t<0) t+=360;
			r[j]+=p[t];
		}
		/*if(r[0]>1) {
			printf("YES");
			return 0;
		}*/
		for(int j=0;j<360;j++) p[j]=r[j];
	}
	if(r[0]>0) {
		printf("YES");
		return 0;
	}
	printf("NO");
	return 0;
}