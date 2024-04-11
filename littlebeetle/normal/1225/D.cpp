#include<cstdio>
const int N=100002;
typedef long long ll;
int n,p,x,s[N],k,cnt;
ll y,z,ans;
void D(int k,int g){
	g%=p;
	int u=g,v=(p-g)%p;
	while(y&&u--){
		y*=k;
		if(y>N)y=0;
	}
	while(z&&v--){
		z*=k;
		if(z>N)z=0;
	}
}
int main(){
	scanf("%d%d",&n,&p);
	while(n--){
		scanf("%d",&x);
		y=z=1;
		for(k=2;k*k<=x;k++)
			if(x%k==0){
				cnt=0;
				while(x%k==0)
					x/=k,cnt++;
				D(k,cnt);
			}
		if(x!=1)
			D(x,1);
		ans+=s[y];
		s[z]++;
	}
	printf("%lld",ans);
	///while(1);
}