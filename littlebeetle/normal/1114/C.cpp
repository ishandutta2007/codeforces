#include<cstdio>
long long n,m,b,x,y,z,i,s,p,q,S=(1ll<<62)-1<<1;
int main(){
	scanf("%I64d%I64d",&m,&b);
	for(i=2;i*i<=b;i++){
		if(b%i==0){
			y=1;z=0;
			while(b%i==0)
				b/=i,y*=i,z++;
			p=i,q=z;
			s=0;n=m;
			while(n)
				s+=n/p,n/=p;
			if(s/q<S)
				S=s/q;
		}
	}
	if(b!=1){
		p=b,q=1;
		s=0;n=m;
		while(n)
			s+=n/p,n/=p;
		if(s/q<S)
			S=s/q;
	}
	printf("%I64d",S);
}