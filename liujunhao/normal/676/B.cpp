#include<cstdio>
#include<cstring>
#include<algorithm>
#define EPS 1e-7
using namespace std;
int ans;
void Read(int &x){
	char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
}
int n,t;
double a[20][20];
int main()
{
	Read(n),Read(t);
	int j,k;
	a[1][1]+=t;
	for(j=1;j<=n;j++)
		for(k=1;k<=j;k++)
			if(a[j][k]>=1)
				a[j+1][k]+=(a[j][k]-1)*0.5,a[j+1][k+1]+=(a[j][k]-1)*0.5,a[j][k]=1;
	for(j=1;j<=n;j++)
		for(k=1;k<=j;k++)
			if(1-a[j][k]<EPS)
				ans++;
	printf("%d\n",ans);
}