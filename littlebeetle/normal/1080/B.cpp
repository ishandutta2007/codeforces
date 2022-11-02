#include<cstdio>
int l,r,q,s;
int g(int x){
	return x&1?-x:x;
}
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&l,&r);
		if(l==r)
			printf("%d\n",g(l));
		else{
			s=0;
			while(l&1)
				s+=g(l++);
			while(~r&1)
				s+=g(r--);
			s-=(r-l+1)/2;
			printf("%d\n",s);
		}
	}
	return 0;
}