# include <iostream>
# include <cstdio>
# include <cstring>
using namespace std;
char a[5002];

int f[5002][5002];
int main()
{
	scanf("%s", a+1); int n=strlen(a+1);
	for(int k=1; k<=n; k++)
		for(int i=0; k-i && k+i<=n; i++)
			if(a[k-i]==a[k+i]) f[k-i][k+i]=1; else break;
	for(int k=1; k<n; k++) if(a[k]==a[k+1])
		for(int i=1; k+1-i && k+i<=n; i++)
			if(a[k+1-i]==a[k+i]) f[k+1-i][k+i]=1; else break;
	for(int k=1; k<n; k++)
		for(int i=1,j=k+1; j<=n; i++,j++)
			f[i][j] += f[i+1][j] + f[i][j-1] - f[i+1][j-1];
	scanf("%d", &n); int L, R;
	while ( n-- ) {
		scanf("%d%d",&L,&R);
		printf("%d\n",f[L][R]);
	}
}