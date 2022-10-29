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

int n,q;
map<int,int> w;
vector<pair<int,int> > v;

int main(){
	scanf("%d%d",&n,&q);
	fore(i,0,n){
		int a;
		scanf("%d",&a);
		w[a]++;
	}
	v=vector<pair<int,int> >(w.begin(),w.end());
	reverse(v.begin(),v.end());
	while(q--){
		int a,r=0;
		scanf("%d",&a);
		for(auto p:v){
			int t=min(a/p.fst,p.snd);
			a-=p.fst*t;
			r+=t;
		}
		if(a)r=-1;
		printf("%d\n",r);
	}
	return 0;
}