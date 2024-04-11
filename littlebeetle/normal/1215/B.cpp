#include<cstdio>
typedef long long ll;
ll s1,s2;
int n,t,a;
int main(){
	scanf("%d",&n);
	t=1;
	s1=1;
	while(n--){
		scanf("%d",&a);
		if(a<0)
			t*=-1;
		if(t==1)
			s1++;
		else
			s2++;
	}
	printf("%lld %lld",s1*s2,s1*(s1-1)/2+s2*(s2-1)/2);
}