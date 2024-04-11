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

int gcd(int a, int b){
	while(b){
		int c=a%b;
		a=b;b=c;
	}
	return a;
}
void div_rec(vector<int>& r, vector<pair<int,int> >& f, int k, int c){
	if(k==f.size()){r.pb(c);return;}
	fore(i,0,f[k].snd+1)div_rec(r,f,k+1,c),c*=f[k].fst;
}
vector<int> divisors(int n){
	vector<pair<int,int> > f;
	for(int i=2;i*i<=n;++i){
		if(n%i==0){
			int k=0;
			while(n%i==0){
				k++;
				n/=i;
			}
			f.pb(mp(i,k));
		}
	}
	if(n>1)f.pb(mp(n,1));
	vector<int> r;
	div_rec(r,f,0,1);
	sort(r.begin(),r.end());
	return r;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int g=0;
	while(n--){
		int k;
		scanf("%d",&k);k--;
		while(k%2==0)k/=2;
		g=gcd(g,k);
	}
	auto v=divisors(g);
	ll r=0;
	for(int d:v){
		while(d<=m-1){
			r+=m-d;
			d*=2;
		}
	}
	printf("%lld\n",r);
	return 0;
}