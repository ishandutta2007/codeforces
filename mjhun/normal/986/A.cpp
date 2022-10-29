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

vector<int> g[100005];
int a[100005];
int n,m,k,s;
int d[105][100005];
queue<int> q;

int main(){
	scanf("%d%d%d%d",&n,&m,&k,&s);
	fore(i,0,n)scanf("%d",a+i),a[i]--;
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	mset(d,-1);
	fore(i,0,k){
		fore(x,0,n)if(a[x]==i)d[i][x]=0,q.push(x);
		while(!q.empty()){
			int x=q.front();q.pop();
			for(int y:g[x])if(d[i][y]<0){
				d[i][y]=d[i][x]+1;
				q.push(y);
			}
		}
	}
	fore(i,0,n){
		vector<int> t;
		fore(j,0,k)t.pb(d[j][i]);//,printf(" %d\n",t.back());
		nth_element(t.begin(),t.begin()+s,t.end());
		ll r=0;
		fore(j,0,s)r+=t[j];
		printf("%lld%c",r," \n"[i==n-1]);
	}
	return 0;
}