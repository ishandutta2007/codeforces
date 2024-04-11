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

vector<int> p={2,3,5,7,11};
vector<int> x;int n;
int q[8];

void go(int k, int c){
	if(k==SZ(p)){x.pb(c);return;}
	while(c<=2*n*n){
		go(k+1,c);
		c*=p[k];
	}
}

int main(){
	scanf("%d",&n);
	if(n<100)p.pop_back();
	go(0,1);
	assert(SZ(x)>=n);
	while(1){
		memset(q,0,sizeof(q));
		random_shuffle(x.begin(),x.end());
		fore(i,0,n)fore(j,0,SZ(p))q[j]+=x[i]%p[j]==0;
		bool can=true;
		fore(i,0,SZ(p))can=can&&(!q[i]||q[i]>=(n+1)/2);
		if(!can)continue;
		fore(i,0,n)printf("%d%c",x[i]," \n"[i==n-1]);
		break;
	}
	return 0;
}