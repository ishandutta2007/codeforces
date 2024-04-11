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

char b[5005];int n,m;
int l[5005],r[5005],u[5005],d[5005];

void init(){
	fill(l,l+n*m,n*m);fill(r,r+n*m,n*m);fill(u,u+n*m,n*m);fill(d,d+n*m,n*m);
	fore(i,0,n){
		int z=n*m;
		fore(j,0,m)if(b[i*m+j]!='.'){
			l[i*m+j]=z;
			r[z]=i*m+j;
			z=i*m+j;
		}
	}
	fore(j,0,m){
		int z=n*m;
		fore(i,0,n)if(b[i*m+j]!='.'){
			u[i*m+j]=z;
			d[z]=i*m+j;
			z=i*m+j;
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,n)scanf("%s",b+i*m);
	int r0=0,r1=0;
	fore(i,0,n)fore(j,0,m)if(b[i*m+j]!='.'){
		init();
		int x=i*m+j,c=0;
		while(x<n*m){
			c++;
			l[r[x]]=l[x];r[l[x]]=r[x];
			u[d[x]]=u[x];d[u[x]]=d[x];
			if(b[x]=='L')x=l[x];
			else if(b[x]=='R')x=r[x];
			else if(b[x]=='U')x=u[x];
			else x=d[x];
		}
		if(c>r0)r0=c,r1=1;
		else if(c==r0)r1++;
	}
	printf("%d %d\n",r0,r1);
	return 0;
}