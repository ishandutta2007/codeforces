#include<cstdio>
int q,x,y,z,l,r,mid;
bool check(int a){
	if(a>x)return 0;
	if(a>y)return 0;
	return x-a+y-a+z>=a;
}
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d%d%d",&x,&y,&z);
		l=0;r=x;
		while(l<r){
			mid=l+r+1>>1;
			if(check(mid))
				l=mid;
			else
				r=mid-1;
		}
		printf("%d\n",l);
	}
}