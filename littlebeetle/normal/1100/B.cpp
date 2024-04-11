#include<cstdio>
const int N=100002;
int n,m,i,a[N],p[N],s[N],t[N],o[N];
int main(){
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		p[a[i]]++;
		s[p[a[i]]]=i;
		t[p[a[i]]]++;
	}
	for(i=1;i<=n;i++)
		if(t[i]==m)
			o[s[i]]=1;
	for(i=1;i<=n;i++)
		printf("%d",o[i]);
}