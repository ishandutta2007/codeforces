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

vector<pair<int,int> > v;

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		int s=0;
		fore(_,0,4){
			int x;
			scanf("%d",&x);
			s+=x;
		}
		v.pb(mp(-s,i));
	}
	sort(v.begin(),v.end());
	fore(i,0,n)if(v[i].snd==0){
		printf("%d\n",i+1);
	}
	return 0;
}