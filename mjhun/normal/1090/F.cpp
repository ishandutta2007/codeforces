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

int n;
map<vector<int>,ll> w;

ll ask(int a, int b, int c){
	vector<int> v={a,b,c};
	sort(v.begin(),v.end());
	if(!w.count(v)){
		printf("? %d %d %d\n",a+1,b+1,c+1);fflush(stdout);
		ll r;
		scanf("%lld",&r);
		w[v]=r;
	}
	return w[v];
}

ll solve(ll ab, ll ac, ll bc){
	ll z=ac-bc; // a-b
	assert((z+ab)%2==0);
	return (z+ab)/2;
}

ll s[5];
ll r[1024];
vector<int> t;

int main(){
	scanf("%d",&n);
	fore(i,0,5)t.pb(i);
	pair<vector<ll>,vector<int> > p=mp(vector<ll>({1LL<<60}),t);
	do {
		vector<ll> qwe;
		fore(i,0,5)fore(j,i+1,5)fore(k,j+1,5)
			qwe.pb(ask(t[i],t[j],t[k]));
		p=min(p,mp(qwe,t));
	} while(next_permutation(t.begin(),t.end()));
	t=p.snd;
	int a=t[0],b=t[1],c=t[3],d=t[4];
	ll pingo=ask(t[1],t[2],t[3]);
	ll concha=ask(t[2],t[3],t[4]);
	fore(i,0,3)s[i]=ask(t[0],t[1],t[2+i]);
	r[a]=solve(s[0],s[2],concha);
	fore(i,0,3)r[t[2+i]]=s[i]-r[a];
	r[b]=pingo-r[t[3]];
	fore(i,5,n){
		ll t=ask(a,b,i);
		if(t<r[a]+r[b])r[i]=t-r[b];
		else if(t>r[a]+r[b])r[i]=t-r[a];
		else {
			t=ask(c,d,i);
			if(t<r[c]+r[d])r[i]=t-r[d];
			else if(t>r[c]+r[d])r[i]=t-r[c];
			else r[i]=r[c];
		}
	}
	putchar('!');
	fore(i,0,n)printf(" %lld",r[i]);
	puts("");
	fflush(stdout);
	return 0;
}