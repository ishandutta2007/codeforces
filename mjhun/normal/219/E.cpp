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

set<int> o;int p[1<<20];
set<pair<int,int> > q; // -space, pos
int n,m;

int main(){
	scanf("%d%d",&n,&m);
	q.insert(mp(-(1<<30),0));
	while(m--){
		int t,k;
		scanf("%d%d",&t,&k);
		if(t==1){
			if(n==1){puts("1");continue;}
			printf("%d\n",(p[k]=q.begin()->snd)+1);
			q.erase(q.begin());
			auto it=o.lower_bound(p[k]);
			if(it!=o.end()){
				if(p[k]+1<*it)q.insert(mp(-((*it-p[k])/2),(*it+p[k])/2));
			}
			else if(p[k]!=n-1){
				q.insert(mp(-(n-1-p[k]),n-1));
			}
			if(it!=o.begin()){
				--it;
				if(*it+1<p[k])q.insert(mp(-((p[k]-*it)/2),(*it+p[k])/2));
			}
			else if(p[k]){
				q.insert(mp(-p[k],0));
			}
			o.insert(p[k]);
		}
		else {
			if(n==1)continue;
			o.erase(p[k]);
			auto it=o.lower_bound(p[k]);
			if(it!=o.end()){
				if(p[k]+1<*it)q.erase(mp(-((*it-p[k])/2),(*it+p[k])/2));
			}
			else if(p[k]!=n-1){
				q.erase(mp(-(n-1-p[k]),n-1));
			}
			if(it!=o.begin()){
				--it;
				if(*it+1<p[k])q.erase(mp(-((p[k]-*it)/2),(*it+p[k])/2));
			}
			else if(p[k]){
				q.erase(mp(-p[k],0));
			}
			if(!SZ(o))q.insert(mp(-(1<<30),0));
			else {
				auto it=o.lower_bound(p[k]);
				if(it==o.begin())q.insert(mp(-*it,0));
				else if(it==o.end())q.insert(mp(-(n-1-*(--it)),n-1));
				else {
					int b=*it;
					int a=*(--it);
					q.insert(mp(-((b-a)/2),(b+a)/2));
				}
			}
		}
	}
	return 0;
}