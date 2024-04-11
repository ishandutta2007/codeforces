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
#define on(x,i) ((x>>i)&1)
using namespace std;
typedef long long ll;

#define K 17

int n,m,x[100005];
set<pair<int,int> > w[32];
ll r;

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,n)scanf("%d",x+i);
	fore(k,0,K){
		int i=0;
		while(i<n){
			if(!on(x[i],k)){i++;continue;}
			int j=i;
			while(j<n&&on(x[j],k))j++;
			w[k].insert(mp(i,j));
			r+=1LL*(j-i)*(j-i+1)/2*(1<<k);
			i=j;
		}
	}
	while(m--){
		int i,v;
		scanf("%d%d",&i,&v);i--;
		fore(k,0,K)if(on(x[i],k)!=on(v,k)){
			if(on(v,k)){
				int a=i,b=i+1;
				vector<pair<int,int> > d;
				auto it=w[k].lower_bound(mp(i,-1));
				if(it!=w[k].end()&&it->fst==i+1){
					r-=1LL*(it->snd-it->fst)*(it->snd-it->fst+1)/2*(1<<k);
					b=it->snd;
					d.pb(*it);
				}
				if(it!=w[k].begin()&&(--it)->snd==i){
					r-=1LL*(it->snd-it->fst)*(it->snd-it->fst+1)/2*(1<<k);
					a=it->fst;
					d.pb(*it);
				}
				for(auto p:d)w[k].erase(p);
				r+=1LL*(b-a)*(b-a+1)/2*(1<<k);
				w[k].insert(mp(a,b));
			}
			else {
				auto it=w[k].lower_bound(mp(i+1,-1));--it;
				r-=1LL*(it->snd-it->fst)*(it->snd-it->fst+1)/2*(1<<k);
				auto p=*it;
				w[k].erase(it);
				if(p.fst!=i){
					r+=1LL*(i-p.fst)*(i-p.fst+1)/2*(1<<k);
					w[k].insert(mp(p.fst,i));
				}
				if(p.snd!=i+1){
					r+=1LL*(p.snd-(i+1))*(p.snd-(i+1)+1)/2*(1<<k);
					w[k].insert(mp(i+1,p.snd));
				}
			}
		}
		x[i]=v;
		printf("%lld\n",r);
	}
	return 0;
}