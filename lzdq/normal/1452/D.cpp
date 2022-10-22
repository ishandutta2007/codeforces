#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5,Mod=998244353;
ll Fstpw(ll a,int b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%Mod;
		b>>=1;
		a=a*a%Mod;
	}
	return res;
}
int n;
int ans;
int main(){
	scanf("%d",&n);
	ll s1=0,s2=1;
	for(int i=1; i<=n; i++){
		s2+=s1;
		s2%=Mod;
		swap(s1,s2);
	}
	//if(n&1) s2++;
	swap(s1,s2);
	//printf("s2 %lld\n",s2);
	ans=s2*Fstpw(Mod+1>>1,n)%Mod;
	printf("%d\n",ans);
	return 0;
}