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
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

set<int> w,r[10005];
set<int> rr;
int k,m;

void add(int x){
	rr.insert(x);
	if(SZ(rr)==m){
		for(int x:rr)printf("%08d\n",x);
		exit(0);
	}
}

void go1(vector<int>& v){
	if(SZ(v)==1){w.insert(abs(v[0]));return;}
	fore(i,0,SZ(v)-1){
		vector<int> w=v;
		w.erase(w.begin()+i);
		w[i]=v[i]+v[i+1];
		go1(w);
		w[i]=v[i]-v[i+1];
		go1(w);
		w[i]=v[i]*v[i+1];
		go1(w);
	}
}

void go0(vector<int>& v, int k, vector<int>& w){
	if(k==SZ(v)){go1(v);return;}
	int x=0;
	while(k<SZ(v)){
		x*=10;x+=v[k];
		w.pb(x);
		k++;
		go0(v,k,w);
		w.pop_back();
	}
}

int main(){
	scanf("%d%d",&k,&m);
	fore(i,0,10000){
		vector<int> v;
		int x=i;
		fore(i,0,4)v.pb(x%10),x/=10;
		reverse(v.begin(),v.end());
		vector<int> z;
		w.clear();
		go0(v,0,z);
		for(int x:w)r[x].insert(i);
	}
	fore(i,1,10000)for(int x:r[i])for(int y:r[abs(k-x)])add(x*10000+y);
	assert(0);
	return 0;
}