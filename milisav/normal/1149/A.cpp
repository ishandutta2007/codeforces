#include<bits/stdc++.h>
using namespace std;
int n;
int c[3];
int main()
{
	scanf("%d",&n);
	int a;
	for(int i=0;i<n;i++) {
		scanf("%d",&a);
		c[a]++;
	}
	if(c[1]==0) {
		for(int i=0;i<n;i++) printf("2 ");
		return 0;
	}
	if(c[2]==0) {
		for(int i=0;i<n;i++) printf("1 ");
		return 0;
	}
	c[1]--;
	c[2]--;
	printf("2 1 ");
	for(int i=0;i<c[2];i++) printf("2 ");
	for(int i=0;i<c[1];i++) printf("1 ");
	return 0;
}