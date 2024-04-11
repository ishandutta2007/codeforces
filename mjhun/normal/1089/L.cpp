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

int n,k;
vector<int> w[100005];
int a[100005],b[100005];
int q;
vector<int> v;

int main(){
	scanf("%d%d",&n,&k);
	fore(i,0,n)scanf("%d",a+i),a[i]--;
	fore(i,0,n)scanf("%d",b+i);
	fore(i,0,n)w[a[i]].pb(b[i]);
	fore(i,0,k){
		sort(w[i].begin(),w[i].end());
		if(!SZ(w[i]))q++;
		fore(j,0,SZ(w[i])-1)v.pb(w[i][j]);
	}
	sort(v.begin(),v.end());
	ll r=0;
	fore(i,0,q)r+=v[i];
	printf("%lld\n",r);
	return 0;
}