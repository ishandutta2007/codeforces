#include<cstdio>
#include<unordered_map>
#include<cmath>
using namespace std;
#define LL long long
inline int add(int a, int b, int mod){return a + b - (a + b >= mod ? mod : 0);}
inline int mul(int a, int b, int mod){ return (long long)a*b%mod; }
int log(int a,int m)
{
	unordered_map<int,int> mp;
	int s=sqrt(m);
	int t=1;
	for(int i=0;i<s;i++){
		mp[t]=i;
		t=(LL)t*a%m;
	}
	for(int i=s,j=t;;i+=s){
		if(mp.count(j))return i-mp[j];
		j=(LL)j*t%m;
	}
}
int power(int a, int b, int mod){
	int ret = 1;
	for (int t = a; b; b >>= 1){
		if (b & 1)ret = mul(ret, t, mod);
		t = mul(t, t, mod);
	}
	return ret;
}
int ans[1200001];
int inv[1200001];
int main()
{
	int n,m,a,q;
	scanf("%d%d%d%d",&n,&m,&a,&q);
	int mod=log(a,q),p=0,c=1;
	inv[1]=1;
	for(int i=2;i<=m+1;i++)
		inv[i]=mul(inv[mod%i],mod-mod/i,mod);
	for(int i=0;i<=m;i++){
		p=add(p,c,mod);
		ans[i]=power(a,p,q);
		c=mul(mul(c,m-i,mod),inv[i+1],mod);
	}
	for(int i=n-1;i>=m;i--)
		printf("%d ",ans[m]);
	for(int i=min(m-1,n-1);i>=0;i--)
		printf("%d ",ans[i]);
}