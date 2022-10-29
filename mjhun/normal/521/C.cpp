#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define MOD 1000000007
using namespace std;

typedef long long ll;

int mul(int a, int b){
	return (1LL*a*b)%MOD;
}

int pm(int a, int e){
	int r=1;
	while(e){
		if(e&1)r=mul(r,a);
		e>>=1;
		a=mul(a,a);
	}
	return r;
}

int inv(int a){
	return pm(a,MOD-2);
}

int f[100005];

int comb(int a, int b){
	if(a<0||b<0||b>a)return 0;
	return mul(f[a],inv(mul(f[b],f[a-b])));
}

char s[100005];
int k,n;
int sp[100005];
int d[100005];

int main(){
	f[0]=1;
	fore(i,1,100005)f[i]=mul(f[i-1],i);
	scanf("%d%d%s",&n,&k,s);
	d[0]=1;
	fore(i,0,100004){
		sp[i+1]=(sp[i]+mul(d[i],comb(n-i-2,k-1)))%MOD;
		d[i+1]=mul(d[i],10);
	}
	int r=0;
	fore(i,0,n){
		r+=mul(s[i]-'0',(sp[n-i-1]+mul(d[n-i-1],comb(i,k)))%MOD);
		r%=MOD;
	}
	printf("%d\n",r);
	return 0;
}