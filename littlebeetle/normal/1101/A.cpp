#include<cstdio>
int n,q,l,r,d,x;
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d%d%d",&l,&r,&d);
		if(d<l||d>r)
			printf("%d\n",d);
		else
			printf("%d\n",r/d*d+d);
	}
}