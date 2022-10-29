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
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

int gcd(int a, int b){
	while(b){
		int c=a%b;
		a=b;b=c;
	}
	return a;
}

const int N=1<<20;

int f[N]; // menor max para llegar
int m,a,b;
priority_queue<pair<int,int> > q;

ll cuentita(ll a, ll b, ll d){ // [a,b)
	if(a>=b)return 0;
	ll t=(a+d-1)/d*d; // primero
	ll k=(b-1)/d*d; // ultimo
	if(t>k)return 0;
	ll q=(k-t)/d+1; // cantidad
	return q*(q-1)/2*d+(b-k)*q;
}

int main(){
	scanf("%d%d%d",&m,&a,&b);
	mset(f,-1);
	f[0]=0;
	q.push(mp(0,0));
	while(!q.empty()){
		int t=q.top().snd;q.pop();
		if(t+a<N&&f[t+a]<0){
			f[t+a]=max(f[t],t+a);
			q.push(mp(-f[t+a],t+a));
		}
		if(t-b>=0&&f[t-b]<0){
			f[t-b]=f[t];
			q.push(mp(-f[t-b],t-b));
		}
	}
	int g=gcd(a,b);
	ll r=0;
	fore(i,0,N)if(f[i]>=0)r+=max(m-f[i]+1,0);
	r+=cuentita(N,m+1,g);
	printf("%lld\n",r);
	return 0;
}