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

int main(){
	int tn;
	scanf("%d",&tn);
	while(tn--){
		scanf("%d",&n);
		int r=0;
		fore(i,0,9){
			vector<int> a,b;
			fore(j,0,n){
				if(j&(1<<i))a.pb(j);
				else b.pb(j);
			}
			if(SZ(a)&&SZ(b)){
				printf("%d %d",SZ(a),SZ(b));
				for(int t:a)printf(" %d",t+1);
				for(int t:b)printf(" %d",t+1);
				puts("");
				fflush(stdout);
				int t;
				scanf("%d",&t);
				r=max(r,t);
			}
		}
		printf("-1 %d\n",r);
		fflush(stdout);
	}
	return 0;
}