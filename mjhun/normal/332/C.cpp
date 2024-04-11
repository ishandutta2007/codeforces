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

int n,p,k;
pair<pair<int,int>,int> x[100005];
vector<pair<int,int> > z;
vector<int> r;


int main(){
	scanf("%d%d%d",&n,&p,&k);
	fore(i,0,n){
		int a,b;
		scanf("%d%d",&a,&b);
		x[i]=mp(mp(b,-a),i);
	}
	sort(x,x+n);
	fore(i,p-k,n)z.pb(mp(-x[i].fst.snd,i));
	sort(z.begin(),z.end());reverse(z.begin(),z.end());
	int l=n;
	fore(i,0,k)r.pb(x[z[i].snd].snd),l=min(l,z[i].snd);
	fore(i,0,p-k)r.pb(x[l-1-i].snd);
	fore(i,0,p)printf("%d%c",r[i]+1," \n"[i==p-1]);
	return 0;
}