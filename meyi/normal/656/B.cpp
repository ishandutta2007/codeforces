#include<cstdio>
int m[16],n,r[16],s;
main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d",m+i);
	for(int i=0;i<n;++i)scanf("%d",r+i);
	for(int j=0;j<720720;++j)
		for(int i=0;i<n;++i)
			if(j%m[i]==r[i]){
				++s;
				break;
			}
	printf("%lf",s/720720.0);
}