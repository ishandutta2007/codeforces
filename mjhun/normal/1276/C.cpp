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
int a[1<<19];
map<int,int> c;
vector<pair<int,int> > v;
vector<int> r[1<<10];

int f(int t){
	int r=0;
	for(auto p:v)r+=min(p.fst,t);
	return r/t;
}

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		int t;
		scanf("%d",&t);
		c[t]++;
	}
	for(auto p:c)v.pb(mp(p.snd,p.fst));
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	pair<int,pair<int,int> > rr=mp(-1,mp(-1,-1));
	fore(i,1,666){
		int j=f(i);
		if(j>=i)rr=max(rr,mp(i*j,mp(i,j)));
	}
	n=rr.snd.fst;
	m=rr.snd.snd;
	fore(i,0,n)r[i].resize(m);
	k=0;
	for(auto p:v)fore(_,0,min(p.fst,n))a[k++]=p.snd;
	k=0;
	fore(j,0,m)fore(i,0,n)r[i][(i+j)%m]=a[k++];
	printf("%d\n%d %d\n",n*m,n,m);
	fore(i,0,n)fore(j,0,m)printf("%d%c",r[i][j]," \n"[j==m-1]);
	return 0;
}