#include <bits/stdc++.h>
using namespace std;
#define N 1000005
int T,cntA1[2],a2[2][N];char a[2][N],a1[2][N];
void slv()
{
	cntA1[0]=cntA1[1]=0;
	for(int i=0,lA;i<2;++i)
	{
		scanf("%s",a[i]+1);lA=strlen(a[i]+1);
		for(int j=1;j<=lA;++j) {if(a[i][j]!=a1[i][cntA1[i]]) a1[i][++cntA1[i]]=a[i][j],a2[i][cntA1[i]]=0;++a2[i][cntA1[i]];}
	}
	if(cntA1[0]!=cntA1[1]) {puts("NO");return;}
	for(int i=1;i<=cntA1[0];++i) if(a1[0][i]!=a1[1][i] || a2[0][i]>a2[1][i]) {puts("NO");return;}
	puts("YES");
}
int main() {scanf("%d",&T);while(T--) slv();}