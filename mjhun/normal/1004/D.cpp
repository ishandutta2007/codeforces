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

map<int,int> c;
map<int,int> c2;

bool valid(int n, int m, int x, int y){
	c2.clear();
	fore(i,0,n)fore(j,0,m)c2[abs(x-i)+abs(y-j)]++;
	return c==c2;
}

void doit(int n, int m){
	int d=c.rbegin()->fst;
	int t=4,k=1;
	while(c[k]==t)k++,t+=4;
	fore(x,0,n){
		int y=d-x;
		if(min(n-x,m-y)==k&&valid(n,m,x,y)){
			printf("%d %d\n%d %d\n",n,m,x+1,y+1);
			exit(0);
		}
	}
}

int main(){
	int t;
	scanf("%d",&t);
	fore(i,0,t){
		int x;
		scanf("%d",&x);
		c[x]++;
	}
	if(t==1&&c[0]){puts("1 1\n1 1");return 0;}
	for(int i=1;i*i<=t;++i)if(t%i==0)doit(i,t/i);
	puts("-1");
	return 0;
}