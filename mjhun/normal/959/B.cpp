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

map<string,int> id;
string s[100005];
char _s[32];
int c[100005],v[100005],g[100005];
int k,n,m;


int main(){
	scanf("%d%d%d",&n,&k,&m);
	fore(i,0,n){
		scanf("%s",_s);
		s[i]=string(_s);
		id[s[i]]=i;
	}
	fore(i,0,n)scanf("%d",c+i);
	fore(i,0,k){
		int q;
		scanf("%d",&q);
		v[i]=1<<30;
		while(q--){
			int j;
			scanf("%d",&j);j--;
			v[i]=min(v[i],c[j]);
			g[j]=i;
		}
	}
	ll r=0;
	fore(_,0,m){
		scanf("%s",_s);
		int i=id[string(_s)];
		r+=v[g[i]];
	}
	printf("%lld\n",r);
	return 0;
}