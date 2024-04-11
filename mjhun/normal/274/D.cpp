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

int n,m,k;
int x[100005];
vector<int> g[300005];
int d[300005];
vector<pair<int,int> > w;
queue<int> q;
vector<int> r;

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,n*m)scanf("%d",x+i);
	k=m;
	fore(i,0,n){
		w.clear();
		fore(j,0,m)if(x[i*m+j]>=0)w.pb(mp(x[i*m+j],j));
		sort(w.begin(),w.end());
		int ii=0,p;
		while(ii<SZ(w)){
			int j=ii;
			while(j<SZ(w)&&w[j].fst==w[ii].fst)j++;
			if(ii)fore(l,ii,j)g[p].pb(w[l].snd);
			if(j<SZ(w)){
				p=k++;
				fore(l,ii,j)g[w[l].snd].pb(p);
			}
			ii=j;
		}
	}
	fore(i,0,k)for(int j:g[i])d[j]++;
	fore(i,0,k)if(!d[i])q.push(i);
	int t=k;
	while(!q.empty()){
		int x=q.front();q.pop();t--;
		if(x<m)r.pb(x);
		for(int y:g[x]){
			d[y]--;
			if(!d[y])q.push(y);
		}
	}
	if(t){puts("-1");return 0;}
	fore(i,0,m)printf("%d%c",r[i]+1," \n"[i==m-1]);
	return 0;
}