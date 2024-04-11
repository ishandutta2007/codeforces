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

int n,k,m;
priority_queue<pair<ll,int> > q[200005];
priority_queue<pair<ll,pair<int,int> > > z; // en tiempo -0, 1 llega a 2
int r0[200005];ll r1[200005];
ll t[200005];int a[200005],b[200005];
queue<int> s; // cola de requests
int h=0; // cantidad de taxis disponibles
multiset<int> w; // posiciones donde hay taxi

void solve(int i){
	assert(h);
	h--;
	auto it=w.lower_bound(a[i]);
	if(it==w.begin()){
		auto p=q[*it].top();q[*it].pop();
		r0[i]=-p.snd;
		r1[i]=max(t[i],-p.fst)+abs(*it-a[i])-t[i];
		z.push(mp(-(max(t[i],-p.fst)+abs(*it-a[i])+abs(a[i]-b[i])),mp(-p.snd,b[i])));
		w.erase(it);
	}
	else {
		auto it2=prev(it);
		if(it==w.end()){
			auto p=q[*it2].top();q[*it2].pop();
			r0[i]=-p.snd;
			r1[i]=max(t[i],-p.fst)+abs(*it2-a[i])-t[i];
			z.push(mp(-(max(t[i],-p.fst)+abs(*it2-a[i])+abs(a[i]-b[i])),mp(-p.snd,b[i])));
			w.erase(it2);
		}
		else {
			if(abs(*it-a[i])<abs(*it2-a[i])){
				auto p=q[*it].top();q[*it].pop();
				r0[i]=-p.snd;
				r1[i]=max(t[i],-p.fst)+abs(*it-a[i])-t[i];
				z.push(mp(-(max(t[i],-p.fst)+abs(*it-a[i])+abs(a[i]-b[i])),mp(-p.snd,b[i])));
				w.erase(it);
			}
			else if(abs(*it2-a[i])<abs(*it-a[i])){
				auto p=q[*it2].top();q[*it2].pop();
				r0[i]=-p.snd;
				r1[i]=max(t[i],-p.fst)+abs(*it2-a[i])-t[i];
				z.push(mp(-(max(t[i],-p.fst)+abs(*it2-a[i])+abs(a[i]-b[i])),mp(-p.snd,b[i])));
				w.erase(it2);
			}
			else if(q[*it].top()>q[*it2].top()){
				auto p=q[*it].top();q[*it].pop();
				r0[i]=-p.snd;
				r1[i]=max(t[i],-p.fst)+abs(*it-a[i])-t[i];
				z.push(mp(-(max(t[i],-p.fst)+abs(*it-a[i])+abs(a[i]-b[i])),mp(-p.snd,b[i])));
				w.erase(it);
			}
			else {
				auto p=q[*it2].top();q[*it2].pop();
				r0[i]=-p.snd;
				r1[i]=max(t[i],-p.fst)+abs(*it2-a[i])-t[i];
				z.push(mp(-(max(t[i],-p.fst)+abs(*it2-a[i])+abs(a[i]-b[i])),mp(-p.snd,b[i])));
				w.erase(it2);
			}
		}
	}
}

int main(){
	scanf("%d%d%d",&n,&k,&m);
	fore(i,0,k){
		int x;
		scanf("%d",&x);x--;
		q[x].push(mp(0,-i));
		w.insert(x);
		h++;
	}
	fore(i,0,m){
		scanf("%lld%d%d",t+i,a+i,b+i);a[i]--;b[i]--;
		while(!z.empty()&&-z.top().fst<=t[i]){
			auto pp=z.top();
			while(!z.empty()&&z.top().fst==pp.fst){
				auto p=z.top();z.pop();
				h++;
				q[p.snd.snd].push(mp(p.fst,-p.snd.fst));
				w.insert(p.snd.snd);
			}
			while(h&&!s.empty()){solve(s.front());s.pop();}		
		}
		if(h)solve(i);
		else s.push(i);
	}
	while(!s.empty()){
		auto pp=z.top();
		while(!z.empty()&&z.top().fst==pp.fst){
			auto p=z.top();z.pop();
			h++;
			q[p.snd.snd].push(mp(p.fst,-p.snd.fst));
			w.insert(p.snd.snd);
		}
		while(!s.empty()&&h){
			solve(s.front());
			s.pop();
		}
	}
	fore(i,0,m)printf("%d %lld\n",r0[i]+1,r1[i]);
	return 0;
}