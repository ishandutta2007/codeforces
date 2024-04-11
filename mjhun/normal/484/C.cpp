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

char s[1<<20],t[1<<20];
int n,nq,m,d;
int f[1<<20];
int g[20][1<<20],w[20][1<<20];

pair<int,int> doit(int x, int e){
	int ww=0;
	fore(k,0,20)if(e&(1<<k)){
		int y=g[k][x];
		if(y<0){ww+=w[k][x];x=y;break;}
		x=y;ww+=1<<k;
	}
	return mp(x,ww);
}

int main(){
	scanf("%s%d",s,&nq);n=strlen(s);
	while(nq--){
		scanf("%d%d",&m,&d);
		int c=0;
		fore(i,0,d)for(int j=i;j<m;j+=d)f[j]=c++;
		assert(c==m);
		fore(i,0,m)g[0][i]=f[i]-1,w[0][i]=g[0][i]<0;
		fore(k,1,20)fore(i,0,m){
			if(g[k-1][i]<0){
				g[k][i]=-1;
				w[k][i]=w[k-1][i];
			}
			else {
				g[k][i]=g[k-1][g[k-1][i]];
				if(g[k][i]<0)w[k][i]=(1<<(k-1))+w[k-1][g[k-1][i]];
			}
		}
		fore(i,0,n){
			int r;
			if(i<m){
				auto p=doit(i,n-m+1);
				if(p.fst>=0)r=n-m+p.fst+1;
				else r=p.snd-1;
			}
			else {
				auto p=doit(m-1,n-i);
				if(p.fst>=0)r=n-m+p.fst+1;
				else r=i-m+p.snd;
			}
			t[r]=s[i];
		}
		memcpy(s,t,n*sizeof(char));
		puts(s);
	}
	return 0;
}