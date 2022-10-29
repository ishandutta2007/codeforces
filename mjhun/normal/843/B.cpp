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

int nq;

pair<int,int> ask(int k){
	nq++;
	assert(nq<2000);
	printf("? %d\n", k);fflush(stdout);
	int a,b;
	scanf("%d%d",&a,&b);
	assert(a>=0);
	return mp(a,b);
}

int n,s,x;
pair<int,int> b;
vector<int> p;


int main(){
	srand(time(0));
	while(scanf("%d%d%d",&n,&s,&x)!=EOF){
		fore(i,1,n+1)p.pb(i);
		random_shuffle(p.begin(),p.end());
		b=ask(s);
		if(b.fst>=x){printf("! %d\n",b.fst);fflush(stdout);return 0;}
		fore(i,0,min(1000,n)){
			int k=p[i];
			auto p=ask(k);
			if(p.fst<=x)b=max(b,p);
		}
		while(b.fst<x&&b.snd>0)b=ask(b.snd);
		if(b.fst>=x)printf("! %d\n",b.fst);
		else puts("! -1");
		fflush(stdout);
		return 0;
		//puts("");
	}
	return 0;
}