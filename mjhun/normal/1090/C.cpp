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

int n,m,s;
pair<int,int> qq[100005];
set<int> w[100005];
int o[100005],q[100005];
int a,b,qa,qb;
set<int> z;
vector<pair<pair<int,int>,int> > r;

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,n){
		scanf("%d",q+i);
		s+=q[i];
		qq[i]=mp(q[i],i);
		fore(_,0,q[i]){
			int t;
			scanf("%d",&t);t--;
			w[t].insert(i);
		}
	}
	sort(qq,qq+n);
	a=s/n;b=a+1;qb=s%n;qa=n-qb;
	fore(i,0,qa)o[qq[i].snd]=a;
	fore(i,qa,n)o[qq[i].snd]=b;
	fore(i,0,n)if(q[i]<o[i])z.insert(i);
	fore(i,0,m){
		int k=0;
		for(int t:w[i])if(q[t]>o[t]){
			bool asd=false;
			while(1){
				auto it=z.lower_bound(k);
				if(it==z.end()){asd=true;break;}
				k=*it;
				assert(q[k]<o[k]);
				if(w[i].count(k)){k++;continue;}
				r.pb(mp(mp(t,k),i));
				q[t]--;
				q[k]++;
				if(q[k]==o[k])z.erase(k);
				k++;
				break;
			}
			if(asd)break;
		}
	}
	fore(i,0,n){assert(q[i]==o[i]);}
	printf("%d\n",SZ(r));
	for(auto p:r)printf("%d %d %d\n",p.fst.fst+1,p.fst.snd+1,p.snd+1);
	return 0;
}