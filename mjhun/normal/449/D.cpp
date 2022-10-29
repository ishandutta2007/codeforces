#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define MOD 1000000007
using namespace std;

int pw(int a, int b){
	if(!b)return 1;
	if(b%2)return (1LL*a*pw(a,b-1))%MOD;
	int d=pw(a,b/2);
	return (1LL*d*d)%MOD;
}

int n;
int f[21][1<<20];

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		int x;
		scanf("%d",&x);
		f[0][x]++;
	}
	fore(k,1,21){
		fore(x,0,1<<20){
			f[k][x]=f[k-1][x];
			if(!(x&(1<<(k-1))))f[k][x]+=f[k-1][x+(1<<(k-1))];
		}
	}
	int r=0;
	fore(x,0,1<<20){
		int d=pw(2,f[20][x]);
		if(__builtin_popcount(x)%2)r=(1LL*r+MOD-d)%MOD;
		else r=(1LL*r+d)%MOD;
	}
	printf("%d\n",r);
	return 0;
}