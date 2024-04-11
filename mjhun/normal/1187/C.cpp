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

int n,m;
vector<pair<int,int> > xx;
vector<pair<int,int> > x,y;
bool asd[1024];

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,m){
		int t,a,b;
		scanf("%d%d%d",&t,&a,&b);a--;b--;
		if(t==1){
			fore(i,a,b)asd[i]=true;
			x.pb(mp(a,b));
		}
		else y.pb(mp(a,b));
	}
	sort(x.begin(),x.end());
	int s=-1,e=-1;
	for(auto p:x){
		int a=p.fst,b=p.snd;
		if(a<=e)e=max(e,b);
		else {
			if(s>=0)xx.pb(mp(s,e));
			s=a;e=b;
		}
	}
	if(s>=0)xx.pb(mp(s,e));
	//for(auto p:xx)printf(" %d %d\n",p.fst,p.snd);
	x=xx;
	for(auto p:y){
		//int k=lower_bound(x.begin(),x.end(),mp(p.snd,-1))-x.begin();
		//k--;
		//
		bool pingo=false;
		fore(i,p.fst,p.snd)pingo|=!asd[i];
		if(!pingo){puts("NO");return 0;}
		//if(k>=0&&x[k].snd>p.fst){puts("NO");return 0;}
	}
	//for(auto p:x)fore(i,p.fst,p.snd)asd[i]=true;
	int z=1e6;
	printf("YES\n%d",z);
	fore(i,0,n-1){
		if(asd[i])z++;
		else z--;
		printf(" %d",z);
	}
	puts("");
	return 0;
}