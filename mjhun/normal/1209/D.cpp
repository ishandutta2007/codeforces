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

int uf[100005];
int find(int x){
	if(uf[x]<0)return x;
	return uf[x]=find(uf[x]);
}

int n,m;

int main(){
	mset(uf,-1);
	scanf("%d%d",&n,&m);
	int r=m;
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		x=find(x);y=find(y);
		if(x!=y){
			r--;
			uf[x]=y;
		}
	}
	printf("%d\n",r);
	return 0;
}