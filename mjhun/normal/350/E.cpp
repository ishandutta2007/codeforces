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

int n,m,k;
bool w[305];
vector<int> w0,w1;
vector<pair<int,int> > e;

int main(){
	scanf("%d%d%d",&n,&m,&k);
	fore(i,0,k){
		int a;
		scanf("%d",&a);a--;
		w[a]=true;
		w1.pb(a);
	}
	fore(i,0,n)if(!w[i])w0.pb(i);
	if(k==n){puts("-1");return 0;}
	fore(i,0,n)if(i!=w1[0]&&i!=w1[1])e.pb(mp(w1[0],i));
	for(int x:w0)e.pb(mp(w1[1],x));
	fore(i,0,n)fore(j,i+1,n){
		if(i==w1[0]||i==w1[1]||j==w1[0]||j==w1[1])continue;
		e.pb(mp(i,j));
	}
	if(m>SZ(e)){puts("-1");return 0;}
	fore(i,0,m)printf("%d %d\n",e[i].fst+1,e[i].snd+1);
	return 0;
}