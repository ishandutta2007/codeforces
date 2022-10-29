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

int n,d,k;
int m,z[400005];
vector<pair<int,int> > r;

void add(int i, int j){
	r.pb(mp(i,j));
	z[i]++;z[j]++;
}

void go(int x, int d){
	if(d==0)return;
	while(z[x]<k&&m<n){
		m++;
		add(x,m-1);
		go(m-1,d-1);
	}
}

int main(){
	scanf("%d%d%d",&n,&d,&k);
	if(d==1){
		if(n==2){puts("YES\n1 2");return 0;}
		puts("NO");return 0;
	}
	if(k==1){puts("NO");return 0;}
	if(n<1+d){puts("NO");return 0;}
	fore(i,0,d)add(i,i+1);
	m=1+d;
	fore(i,1,d)go(i,min(i,d-i));
	if(m<n){puts("NO");return 0;}
	assert(m==n&&SZ(r)==n-1);
	puts("YES");
	for(auto p:r)printf("%d %d\n",p.fst+1,p.snd+1);
	return 0;
}