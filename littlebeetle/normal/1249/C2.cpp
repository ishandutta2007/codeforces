#include<cstdio>
const int N=60;
typedef long long ll;
int q,i,f[N],c,x;
ll n,m,k[N];
int main(){
	scanf("%d",&q);
	k[0]=1;
	for(i=1;i<N;i++)
		k[i]=k[i-1]*3;
	while(q--){
		for(i=0;i<N;i++)
			f[i]=0;
		scanf("%lld",&n);
		m=n;
		x=-1;
		for(c=0;n;n/=3,c++){
			f[c]=n%3;
			if(f[c]==2)
				x=c;
		}
		if(x==-1)
			printf("%lld\n",m);
		else{
			for(i=x+1;f[i]==1;i++);
			m=k[i];
			while(i<=c){
				m+=f[i]*k[i];
				i++;
			}
			printf("%lld\n",m);
		}
	}
}