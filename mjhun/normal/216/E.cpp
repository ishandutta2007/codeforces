#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

int b,k,n,MOD,x[100005];ll r;
map<int,int> c;

int main(){
	scanf("%d%d%d",&b,&k,&n);MOD=b-1;
	fore(i,0,n)scanf("%d",x+i);
	ll w=0;
	for(int i=0;i<n;){
		if(x[i]){i++;continue;}
		int j=i;
		while(j<n&&!x[j])j++;
		w+=1LL*(j-i)*(j-i+1)/2;
		i=j;
	}
	if(!k)r=w;
	else {
		k%=MOD;
		int p=1,s=0;
		c[0]++;
		for(int i=n-1;i>=0;--i){
			s+=1LL*p*x[i]%MOD;s%=MOD;
			p=1LL*p*b%MOD;
			r+=c[(s-k+MOD)%MOD];
			c[s]++;
		}
		if(!k)r-=w;
	}
	printf("%lld\n",r);
	return 0;
}