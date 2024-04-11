#include<cstdio>
#include<algorithm>
int a,b,c,d[7];
main(){
	scanf("%d%d%d",&a,&b,&c);
	d[1]=a+b+c;
	d[2]=a*b*c;
	d[3]=a+b*c;
	d[4]=(a+b)*c;
	d[5]=a*b+c;
	d[6]=a*(b+c);
	std::sort(d+1,d+7);
	printf("%d",d[6]);
}