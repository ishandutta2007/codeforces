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

vector<int> g[100005];
int n,m,r,t[100005],d[100005];
queue<int> q[2];

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,n)scanf("%d",t+i);
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].pb(y);d[y]++;
	}
	fore(i,0,n)if(!d[i])q[t[i]].push(i);
	for(int k=0;n;k^=1){
		r+=k;
		while(!q[k].empty()){
			int x=q[k].front();q[k].pop();n--;
			for(int y:g[x]){
				d[y]--;
				if(!d[y])q[t[y]].push(y);
			}
		}
	}
	printf("%d\n",r);
	return 0;
}