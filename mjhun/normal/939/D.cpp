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
#define mset(a,v) memset(a,v,sizeof(a))
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

int n,uf[256];char s[100005],t[100005];
vector<pair<char,char> > r;

int find(int x){
	if(uf[x]<0)return x;
	return uf[x]=find(uf[x]);
}
void join(int x, int y){uf[x]=y;}

int main(){
	memset(uf,-1,sizeof(uf));
	scanf("%d%s%s",&n,s,t);
	fore(i,0,n){
		int x=find(s[i]),y=find(t[i]);
		if(x!=y){r.pb(mp(s[i],t[i]));join(x,y);}
	}
	printf("%d\n",SZ(r));
	for(auto p:r)printf("%c %c\n",p.fst,p.snd);
	return 0;
}