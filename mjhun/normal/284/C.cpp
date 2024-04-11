#include <cstdio>

int main(){
	int n,t,size=1,a,b,i;
	long long int sum=0;
	int v[200005];
	int s[200005];
	v[0]=0;
	s[0]=0;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&t);
		switch(t){
			case 1:
				scanf("%d %d",&a,&b);
				s[a-1]+=b;
				sum+=b*a;
				break;
			case 2:
				scanf("%d",&a);
				v[size]=a;
				s[size]=0;
				++size;
				sum+=a;
				break;
			case 3:
				s[size-2]+=s[size-1];
				sum-=v[size-1]+s[size-1];
				size--;
				break;
		}
		printf("%.8f\n",((double)sum/size));
	}
	return 0;
}