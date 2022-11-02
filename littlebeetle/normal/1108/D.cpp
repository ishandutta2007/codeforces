#include<cstdio>
const int N=200200;
char s[N],c[5]="BGR";
int n,i,p,a[N],b[200];
int main(){
	scanf("%d%s",&n,s+1);
	b['B']=0;
	b['G']=1;
	b['R']=2;
	for(i=1;i<=n;i++)
		a[i]=b[s[i]];
	a[n+1]=5;
	for(i=2;i<=n;i++)
		if(a[i]==a[i-1]){
			p++;
			a[i]=(a[i]+1)%3;
			if(a[i]==a[i+1])
				a[i]=(a[i]+1)%3;
		}
	for(i=1;i<=n;i++)
		s[i]=c[a[i]];
	printf("%d\n%s",p,s+1);
}