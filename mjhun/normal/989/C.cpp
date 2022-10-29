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

#define M 48

char r[64][64];
int a,b,c,d;

int main(){
	scanf("%d%d%d%d",&a,&b,&c,&d);
	fore(i,0,M/2)fore(j,0,M)r[i][j]='A';
	fore(i,M/2,M)fore(j,0,M)r[i][j]='B';
	a--;b--;
	for(int i=0;i<M/2;i+=2){
		for(int j=0;j<M;j+=2){
			if(b)r[i][j]='B',b--;
			else if(c)r[i][j]='C',c--;
		}
	}
	for(int i=M/2+1;i<M;i+=2){
		for(int j=0;j<M;j+=2){
			if(a)r[i][j]='A',a--;
			else if(d)r[i][j]='D',d--;
		}
	}
	assert(!a&&!b&&!c&&!d);
	printf("%d %d\n",M,M);
	fore(i,0,M)puts(r[i]);
	return 0;
}