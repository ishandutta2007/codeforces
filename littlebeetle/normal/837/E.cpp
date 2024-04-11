#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=2000020;
ll a,b,c,s,x[N],t,i,j,k,o,u=3;
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
int main(){
	scanf("%lld%lld",&a,&b);
	c=a;
    for(i=2;i*i<=c;i++)
        if(c%i==0){
            x[++t]=i;
            while(c%i==0)
                c/=i;
        }
    if(c!=1)
        x[++t]=c;
	while(b){
		//printf("%lld %lld\n",a,b);
		o=gcd(a,b);
		a/=o;b/=o;
		if(a==b){
			s++;
			break;
		}
		k=0;
		for(j=1;j<=t;j++)
			if(a%x[j]==0&&b/x[j]*x[j]>k)
					k=b/x[j]*x[j];

		s+=b-k;
		b=k;
	}
	printf("%lld",s);
}