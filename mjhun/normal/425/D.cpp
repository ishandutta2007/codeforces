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

int n;
pair<int,int> p[100005];
vector<int> w[100005];

bool ok(int x, int y){return binary_search(p,p+n,mp(x,y));}

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		int x,y;
		scanf("%d%d",&x,&y);
		p[i]=mp(x,y);
		w[x].pb(y);
	}
	sort(p,p+n);
	int r=0;
	fore(x,0,100005){
		sort(w[x].begin(),w[x].end());
		if(SZ(w[x])<316){
			fore(i,0,SZ(w[x]))fore(j,i+1,SZ(w[x])){
				int y0=w[x][i],y1=w[x][j];
				r+=ok(x-(y1-y0),y0)&&ok(x-(y1-y0),y1);
			}
		}
		else {
			fore(i,0,n)if(p[i].fst<x){
				int x0=p[i].fst,y0=p[i].snd;
				r+=ok(x,y0+x-x0)&&ok(x0,y0+x-x0);
			}
		}
	}
	printf("%d\n",r);
	return 0;
}