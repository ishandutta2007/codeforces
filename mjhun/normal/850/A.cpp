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

int n;
vector<int> a[1024];

bool asd(int i, int j, int k){
	int r=0;
	fore(_,0,5)r+=(a[j][_]-a[i][_])*(a[k][_]-a[i][_]);
	return r>0;
}

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		fore(_,0,5){
			int k;
			scanf("%d",&k);
			a[i].pb(k);
		}
	}
	vector<int> r;
	fore(i,0,n){
		bool g=true;
		fore(j,0,n){
			if(j==i)continue;
			fore(k,j+1,n){
				if(k==i)continue;
				if(asd(i,j,k)){g=false;break;}
			}
			if(!g)break;
		}
		if(g)r.pb(i);
	}
	printf("%d\n",SZ(r));
	for(int x:r)printf("%d\n",x+1);
	return 0;
}