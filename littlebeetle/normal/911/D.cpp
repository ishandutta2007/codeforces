#include<cstdio>
const int N=1502;
int n,a,c[N],x,i,s,l,r;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		for(x=a+1;x<=n;x+=x&-x)
			s+=c[x];
		for(x=a;x;x-=x&-x)
			c[x]++;
	}
	scanf("%d",&n);
	s%=2;
	while(n--){
		scanf("%d%d",&l,&r);
		s^=(r-l+1)*(r-l)/2&1;
		printf("%s\n",s?"odd":"even");
	}
}