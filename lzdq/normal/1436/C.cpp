#include<cstdio>
typedef long long ll;
const int Mod=1e9+7;
int n,x,pos;
int a,b,c;
int main(){
	scanf("%d%d%d",&n,&x,&pos);
	//n=4,x=1,pos=2;
	int l=0,r=n;
	while(l<r){
		int mid=l+r>>1;
		if(mid==pos) l=mid+1;
		else if(pos<mid) a++,r=mid;
		else b++,l=mid+1;
	}
	//printf("a %d b %d\n",a,b);
	//A(n-x,a)*A(x-1,b)*A(n-a-b,n-a-b)
	ll ans=1;
	for(int i=0; i<a; i++)
		ans=ans*(n-x-i)%Mod;
	for(int i=0; i<b; i++)
		ans=ans*(x-1-i)%Mod;
	//printf("ans %lld\n",ans);
	for(int i=1; i<n-a-b; i++)
		ans=ans*i%Mod;
	printf("%lld\n",ans);
	return 0;
}