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

int n,k,m,a;
int c[128];
int l[128];
vector<pair<pair<int,int>,int> > w;
int p[128];

int doit(int e){
	if(a==m){
		if(!c[e])return 3;
		return p[e]<k?1:3;
	}
	if(n==1)return 1;
	if(n==k)return c[e]?1:2;
	int s=w[k-1].fst.fst;
	if(c[e]+m-a<=s)return 3;
	if(!c[e])return 2;
	if(p[e]>=k)return 2;
	int q=0;
	fore(i,p[e]+1,k+1)q+=c[e]-w[i].fst.fst+1;
	return q<=m-a?2:1;
}

int main(){
	scanf("%d%d%d%d",&n,&k,&m,&a);
	memset(l,-1,sizeof(l));
	fore(i,0,a){
		int x;
		scanf("%d",&x);x--;
		c[x]++;
		l[x]=i;
	}
	fore(i,0,n)w.pb(mp(mp(-c[i],l[i]),i));
	sort(w.begin(),w.end());
	fore(i,0,n)w[i].fst.fst*=-1;
	fore(i,0,n)p[w[i].snd]=i;
	fore(i,0,n){
		if(i)putchar(' ');
		printf("%d",doit(i));
	}
	puts("");
	return 0;
}