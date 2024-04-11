#include<cstdio>
int t,n,a,x,y,z;
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		x=y=z=0;
		while(n--){
			scanf("%d",&a);
			if(a%3==0)x++;
			if(a%3==1)y++;
			if(a%3==2)z++;
		}
		x+=min(y,z);
		printf("%d\n",x+(y+z-min(y,z)*2)/3);
	}
}