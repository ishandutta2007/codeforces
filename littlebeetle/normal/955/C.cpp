#include<cstdio>
#include<cmath>
const int N=63;
int n,a[N],u[N],i,j,k;
long long l,r;
bool f[N];
void prepare(){
	u[1]=1;
	for(i=2;i<N;i++){
		if(!f[i])a[k++]=i,u[i]=1;
		for(j=0;(!j||i%a[j-1])&&i*a[j]<N;j++){
			f[i*a[j]]=1;
			u[i*a[j]]=u[i]*(i%a[j]?-1:0);
		}
	}
}
long long Pow(long long x,long long p){
	long long s=1;
	while(p--)
		s*=x;
	return s;
}
long long work(long long x){
	if(x==0)return 0;
	long long s=0,y;
	for(i=2;i<N;i++)
		if(u[i]){
			y=(long long)pow((long double)x+1000,1.0/i);
			while(Pow(y,i)>x)
				y--;
			s+=u[i]*(y-1);
		}
	return s+1;
}
int main(){
	prepare();
	scanf("%d",&n);
	while(n--){
		scanf("%I64d%I64d",&l,&r);
		printf("%I64d\n",work(r)-work(l-1));
	}
}