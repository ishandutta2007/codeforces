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

int n;
vector<pair<int,int> > w[400005];
vector<pair<int,int> > p[2];
//set<pair<pair<int,int>,int> >
multiset<int> s0,s1;

ll doit(vector<pair<int,int> >& p){
	if(!SZ(p))return 0;
	int kk=(p[0].fst+p[0].snd)%2;
	fore(i,0,400005)w[i].clear();
	for(auto q:p)w[q.fst+q.snd].pb(q);
	s0.clear();s1.clear();
	for(auto q:p){
		s1.insert(q.fst-q.snd);
	}
	ll r=0;
	fore(i,0,400005){
		if(i%2==kk){
			for(auto q:w[i])s1.erase(s1.find(q.fst-q.snd)),s0.insert(q.fst-q.snd);
			/*if(SZ(w[i])){
				//puts("holis");
			}*/
		}
		else {
			if(!SZ(s0)||!SZ(s1))continue;
			int mn=max(*s0.begin(),*s1.begin()),mx=min(*s0.rbegin(),*s1.rbegin());
			/*if(mx-mn+1){
				for(int x:s0)printf(" %d",x-100000);puts("");
				for(int x:s1)printf(" %d",x-100000);puts("");
				printf(" asd %d %d %d\n",mn-100000,mx-100000,mx-mn+1);
			}*/
			//printf(" %d %d\n",mx,mn);
			if(mn<=mx)r+=(mx-mn)/2;
		}
	}
	return r;
}

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		int x,y;
		scanf("%d%d",&x,&y);x+=100000;y+=100000;
		p[(x+y)%2].pb(mp(x,y));
	}
	printf("%lld\n",doit(p[0])+doit(p[1]));
	return 0;
}