#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define MOD 1000000007
using namespace std;

typedef long long ll;

int mul(int a, int b, int mod){
	return (1LL*a*b)%mod;
}

int pm(int a, int e){
	int r=1,t=a;
	while(e){
		if(e&1)r=mul(r,t,MOD);
		e>>=1;
		t=mul(t,t,MOD);
	}
	return r;
}

map<int,int> f;

int main(){
	int m;
	scanf("%d",&m);
	while(m--){
		int p;
		scanf("%d",&p);
		f[p]++;
	}
	int nd=1,r=1;
	for(map<int,int>::iterator it=f.begin();it!=f.end();++it){
		int p=it->fst,q=it->snd;
		int t=((1LL*q*(q+1))/2)%(MOD-1);
		t=(1LL*t*nd)%(MOD-1);
		r=mul(pm(r,q+1),pm(p,t),MOD);
		nd=mul(nd,q+1,MOD-1);
	}
	printf("%d\n",r);
	return 0;
}