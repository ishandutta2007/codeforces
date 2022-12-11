#include<cstdio>

using namespace std;

int a[10001];
int xw(int o){
	printf("%d\n",o);
	fflush(stdout);
	int z;
	scanf("%d",&z);
	return z;
}
int main(){
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++){
		int z=xw(1);
		if(z==0){
			return 0;
		}
		a[i]=z==-1?0:1;
	}
	int l=1,r=m,o=1;
	while(l^r){
		int mid=l+r>>1;
		int z=xw(mid);
		if(!a[o])z=-z;
		o=o%n+1;
		if(!z)return 0;
		if(z==-1)r=mid;
		else l=mid+1;
	}
	xw(l);
}