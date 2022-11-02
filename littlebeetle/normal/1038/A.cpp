#include<cstdio>
char s[100002];
int n,k,i,p[26],f=1<<30;
int main(){
	scanf("%d%d%s",&n,&k,s);
	for(i=0;i<n;i++)
		p[s[i]-65]++;
	for(i=0;i<k;i++)
		if(p[i]<f)
			f=p[i];
	printf("%d",f*k);
}
/////