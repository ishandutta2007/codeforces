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

int n;ll T;
ll r[100005];

queue<int> qq;
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q; // tiempo persona

set<int> w,s; // waiting, seated

int main(){
	scanf("%d%lld",&n,&T);
	fore(i,0,n){
		ll t;
		scanf("%lld",&t);
		q.push(mp(t,i));
	}
	while(!q.empty()){
		auto p=q.top();
		q.pop();
		int i=p.snd;
		if(i>=0){
			if(w.empty()||*w.begin()>i){ // voy
				if(qq.empty()){
					q.push(mp(p.fst+T,-i-1));
				}
				qq.push(i);
				w.insert(i);
			}
			else { // no voy
				s.insert(i);
			}
		}
		else {
			i=-i-1;
			r[i]=p.fst;
			assert(qq.front()==i);
			qq.pop();
			w.erase(i);
			auto it=s.upper_bound(i);
			if(it!=s.end()){
				int j=*it;
				q.push(mp(p.fst,j));
				s.erase(j);
			}
			if(!qq.empty()){
				q.push(mp(p.fst+T,-qq.front()-1));
			}
		}
	}
	fore(i,0,n)printf("%lld%c",r[i]," \n"[i==n-1]);
	return 0;
}