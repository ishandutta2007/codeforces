#include<cstdio>
const int N=20,M=1000000007;
int x,y,n,i,f[N];
int main(){
	scanf("%d%d%d",&x,&y,&n);
	x=(x+M)%M;
	y=(y+M)%M;
	n=n%6+6;
	f[1]=x;f[2]=y;
	for(i=3;i<=n;i++)
		f[i]=(f[i-1]-f[i-2]+M)%M;
	printf("%d",f[n]);
	//while(1);
}