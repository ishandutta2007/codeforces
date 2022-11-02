#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int N=1000020;
typedef long long ll;
int n,i,j,k,a[N],b[N],c[N],l,r,mid;
ll s,x,p,Ans=1ll<<60,Sum;
void init(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		s+=a[i];
	}
}
int abs(int x){
	return x>0?x:-x;
}
void check(ll x){
	Sum=0;
	for(i=1;i<=n+1;i++)
		b[i]=a[i]%x,c[i]=0;
	l=1;
	while(l<=n){
		p=0;
		for(r=l;r<=n;r++){
			if(p+b[r]>=x){
				c[r]=x-p;
				b[r]-=c[r];
				break;
			}
			else{
				c[r]=b[r];
				p+=b[r];
				b[r]=0;
			}
		}
		p=0;
		for(i=l;i<=r;i++){
			p+=c[i];
			if(p*2>=x)
				break;
		}
		mid=i;
		for(i=l;i<=r;i++){
			Sum+=1ll*c[i]*abs(i-mid);
			c[i]=0;
		}
		if(b[r]==0)
			l=r+1;
		else
			l=r;
	}
	if(Sum<Ans)
		Ans=Sum;
}
void work(){
	for(x=2;x*x<=s;x++)
		if(s%x==0){
			check(x);
			while(s%x==0)
				s/=x;
		}
	if(s>1)
		check(s);
	printf("%lld",Ans==(1ll<<60)?-1:Ans);
}
int main(){
	init();
	work();
	return 0;
}