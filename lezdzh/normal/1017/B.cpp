#include<cstdio>

using namespace std;

char a[100002],b[100002];
int k[4];
int main(){
	int n;
	scanf("%d%s%s",&n,a+1,b+1);
	for(int i=1;i<=n;i++)
		k[(a[i]=='1')*2+(b[i]=='1')]++;
	printf("%I64d\n",1ll*(k[0]+k[1])*(k[2]+k[3])-1ll*k[1]*k[3]);
}