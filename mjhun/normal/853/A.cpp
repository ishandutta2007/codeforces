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

int n,k;
set<pair<int,int> > w;
int x[1<<20];
int v[1<<20];
int r[1<<20];
ll rr;

int main(){
	while(scanf("%d%d",&n,&k)!=EOF){
		w.clear();rr=0;
		fore(i,0,n){
			scanf("%d",v+i);
			w.insert(mp(v[i],i));
		}
		fore(i,0,n)x[i]=i;
		fore(i,n,n+k)x[i]=-1;
		for(int i=n+k-1;i>=0;--i){
			//puts("holis");
			if(x[i]<0){
				if(w.empty())continue;
				auto p=*w.begin();
				w.erase(w.begin());
				int j=p.snd;
				rr+=1LL*p.fst*(i-j);
				x[j]=-1;
				r[j]=i;
			}
			else {
				r[i]=i;
				w.erase(mp(v[i],i));
			}
		}
		printf("%lld\n",rr);
		fore(i,0,n){
			if(i)putchar(' ');
			printf("%d",r[i]+1);
		}
		puts("");
		puts("");
	}
	return 0;
}