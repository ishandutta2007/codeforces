#include <cstdio>
int degs[10];
int main()
{
	int t,a,b,i;
	scanf("%d",&t); degs[0]=(t*30+1)%360; degs[1]=degs[0]+360;
	scanf("%d",&t); degs[2]=(t*6+1)%360; degs[3]=degs[2]+360;
	scanf("%d",&t); degs[4]=(t*6)%360; degs[5]=degs[4]+360;
	scanf("%d%d",&a,&b); a=(a*30)%360; b=(b*30)%360;
	if(b<a) b+=360;
	for(i=0;i<6;i++)
		if(a<degs[i] && degs[i]<b)
			break;
	if(i==6) { printf("YES\n"); return 0; }
	a%=360; b%=360;
	if(b>a) a+=360;
	for(i=0;i<6;i++)
		if(b<degs[i] && degs[i]<a)
			break;
	if(i==6) { printf("YES\n"); return 0; }
	printf("NO\n");
    return 0;
}