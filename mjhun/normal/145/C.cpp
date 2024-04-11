#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define MOD 1000000007
using namespace std;
typedef long long ll;

bool lucky(int x){
	while(x){
		int d=x%10;
		if(d!=4&&d!=7)return false;
		x/=10;
	}
	return true;
}

int pm(int a, int e){
	int r=1;
	while(e){
		if(e&1)r=(1LL*r*a)%MOD;
		e>>=1;
		a=(1LL*a*a)%MOD;
	}
	return r;
}

int inv(int a){
	return pm(a,MOD-2);
}

int fact[100005];

int comb(int n, int k){
	if(k<0||k>n)return 0;
	return (1LL*fact[n]*inv((1LL*fact[k]*fact[n-k])%MOD))%MOD;
}

map<int,int> w;
int f[100005];
int n,k,nl;

int main(){
	fact[0]=1;
	fore(i,1,100005)fact[i]=(1LL*fact[i-1]*i)%MOD;
	scanf("%d%d",&n,&k);
	fore(i,0,n){
		int x;
		scanf("%d",&x);
		if(lucky(x)){
			w[x]++;
			nl++;
		}
	}
	f[0]=1;
	for(map<int,int>::iterator it=w.begin();it!=w.end();++it){
		int c=it->snd;
		for(int i=k;i>0;--i)f[i]+=(1LL*f[i-1]*c)%MOD,f[i]%=MOD;
	}
	int r=0;
	fore(i,0,k+1){
		r+=(1LL*f[i]*comb(n-nl,k-i))%MOD;
		r%=MOD;
	}
	printf("%d\n",r);
	return 0;
}