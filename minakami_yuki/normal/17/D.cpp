#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring> 
#define LL long long
using namespace std;
const int N=1e6+10;
//const LL P=998244353;
LL P;
LL qpow(LL x,LL y){
	LL re=1;
	while(y){
		if(y&1) re=re*x%P;
		x=x*x%P;y>>=1;
	}
	return re;
}
LL a[N];
char B[N],A[N];
int main(){
	scanf("%s",B+1);
	scanf("%s",A+1);
	cin>>P;
	int l=strlen(B+1);
	LL x,y,z,T=10;
	x=0;y=0;
	for(int i=1;i<=l;++i) {
		y=B[i]-'0';
		x=(x*T+y)%P;
	}
	LL ans=(x+P-1)%P;
	LL b=x;
	l=strlen(A+1);
	for(int i=1;i<=l;i++){
		a[i]=A[i]-'0';
	}
	int now=l;
	while(a[now]==0){
		a[now]=9;
		--now;
	}
	--a[now];
	z=b;
	for(int i=l;i>=1;--i){
		y=a[i];
		ans=ans*qpow(z,y)%P;
		z=qpow(z,T)%P;
	}
	if(ans==0) ans=P;
	cout<<ans<<endl;
	return 0;
}