#include<cstdio>
const int N=500020;
typedef long long ll;
int n,k,i;
ll a[N],b[N],P[61],s;
void Push(ll x){
	for(int i=60;i>=0;i--)
		if(x>>i&1){
			if(!P[i]){
				P[i]=x;
				return;
			}
			x^=P[i];
		}
	k++;
}
bool In(ll s){
	for(int i=60;i>=0;i--)
		if(s>>i&1){
			if(!P[i])
				return 0;
			s^=P[i];
		}
	return 1;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%I64d%I64d",a+i,b+i);
		s^=a[i];
		b[i]^=a[i];
		Push(b[i]);
	}
	if(!In(s)){
		printf("1/1");
		return 0;
	}
	n-=k;
	printf("%I64d/%I64d",(1ll<<n)-1,1ll<<n);
}