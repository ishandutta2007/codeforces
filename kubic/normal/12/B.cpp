#include <bits/stdc++.h>
using namespace std;
#define N 15
int a[2][N];char a1[2][N];bool fl=1;
int main()
{
	scanf("%s %s",a1[0]+1,a1[1]+1);a[0][0]=strlen(a1[0]+1);a[1][0]=strlen(a1[1]+1);
	if(a[0][0]!=a[1][0]) {puts("WRONG_ANSWER");return 0;}
	for(int i=1;i<=a[0][0];++i) a[0][i]=a1[0][i]-48,a[1][i]=a1[1][i]-48;
	sort(a[0]+1,a[0]+a[0][0]+1);if(!a[0][1] && a[0][0]>1) {int t=1;while(!a[0][t]) ++t;a[0][1]=a[0][t];a[0][t]=0;}
	for(int i=1;i<=a[0][0];++i) if(a[0][i]!=a[1][i]) {fl=0;break;}puts(fl?"OK":"WRONG_ANSWER");
}