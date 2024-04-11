#include<bits/stdc++.h>
using namespace std;
int a[100005];
int n;
int m;
int ml;
int cl;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	m=a[0];
	ml=1;
	cl=1;
	for(int i=1;i<n;i++) {
		if(a[i]>m) {
			m=a[i];
			ml=1;
			cl=1;
		}
		else {
			if(a[i]==m) cl++;
			else cl=0;
			ml=max(ml,cl);
		}
	}
	printf("%d",ml);
	return 0;
}