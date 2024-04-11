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

vector<int> g[512];
int d[512],dd[512],n,m;
queue<int> q;

bool doit(){
	memcpy(d,dd,sizeof(d));
	int k=0;
	fore(i,0,n)if(!d[i])q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();k++;
		for(int y:g[x]){
			d[y]--;
			if(!d[y])q.push(y);
		}
	}
	return k==n;
}

int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);dd[y]++;
	}
	fore(i,0,n)if(dd[i]){
		dd[i]--;
		if(doit()){puts("YES");return 0;}
		dd[i]++;
	}
	puts("NO");
	return 0;
}