#include<cstdio>
const int MAXN=2e5+5;
int n,mi,mx;
int a[MAXN];
int gcd(int a,int b){
	if(!b) return a;
	return gcd(b,a%b);
}
int g;
long long sum;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		if(i==1||mi>a[i]) mi=a[i];
	}
	for(int i=1; i<=n; i++){
		a[i]-=mi;
		if(!g) g=a[i];
		else g=gcd(g,a[i]);
		sum+=a[i];
		if(mx<a[i]) mx=a[i];
	}
	printf("%I64d %d\n",(1ll*mx*n-sum)/g,g);
	return 0;
}