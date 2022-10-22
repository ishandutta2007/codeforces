#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1002];
int c[1002];
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<m;i++) scanf("%d",&c[i]);
	int g,h;
	g=0;
	h=0;
	int s=0;
	while(g<n && h<m) {
		if(a[g]<=c[h]) {
			s++;
			h++;
		}
		g++;
	}
	printf("%d",s);
	return 0;
}