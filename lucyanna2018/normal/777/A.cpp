#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,x,a[3];
bool chk(int y){
	memset(a,0,sizeof(a));
	a[y]=1;
	for(int i=1; i<=n; i++)
		if(i%2)swap(a[0],a[1]);else
			swap(a[1],a[2]);
	return a[x]==1;
}
int main(){
	scanf("%d",&n); n%=6;
	scanf("%d",&x);
	for(int i=0; i<=2; i++)
		if(chk(i)){
			printf("%d\n",i);
			break;
		}
	return 0;
}