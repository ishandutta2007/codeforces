#include<stdio.h>
#include<string.h>
#define ran 222222
int n,m,a[ran];
char s1[ran],s2[ran],s3[ran];
bool f[ran];
bool ok(int x){
	memset(f,0,sizeof(f));
	for(int i=1; i<=x; i++)
		f[a[i]] = true;
	m=0;
	for(int i=1; i<=n; i++)
		if(!f[i])
			s3[m++] = s1[i-1];
	for(int i=0,pnt=0; s2[i]; i++){
		while(pnt < m && s3[pnt] != s2[i])
			pnt++;
		if(pnt == m)return false;
		pnt++;
	}
	return true;
}
int main(){
	scanf("%s%s",s1,s2);
	n = strlen(s1);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	int lo = 0, hi = n;
	while(lo != hi){
		int mi = (lo + hi + 1)/2;
		if(ok(mi))lo = mi;else
			hi = mi-1;
	}
	printf("%d\n",lo);
	return 0;
}