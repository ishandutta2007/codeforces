#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define K 40
using namespace std;

typedef long long ll;

int t[1<<22][2];
int nt;

void add(ll x){
	int k=0;
	for(int i=K-1;i>=0;--i){
		int d=(x>>i)&1;
		if(t[k][d]<0)t[k][d]=nt++;
		k=t[k][d];
	}
}


ll query(ll x){
	int k=0;
	ll r=0;
	for(int i=K-1;i>=0;--i){
		int d=(x>>i)&1;
		if(t[k][d^1]>=0){
			k=t[k][d^1];
			r|=(1LL<<i);
		}
		else k=t[k][d];
	}
	return r;
}

ll a[100005];
ll l[100005];
ll r[100005];
int n;

int main(){
	memset(t,-1,sizeof(t));nt=1;
	scanf("%d",&n);
	fore(i,0,n)scanf("%lld",a+i);
	l[0]=0;
	fore(i,1,n+1)l[i]=l[i-1]^a[i-1];
	r[n]=0;
	for(int i=n-1;i>=0;--i)r[i]=r[i+1]^a[i];
	ll s=0;
	fore(i,0,n+1){
		add(l[i]);
		s=max(s,query(r[i]));
	}
	printf("%lld\n",s);
	return 0;
}