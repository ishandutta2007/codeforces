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


int n;
int x[2048];
int w[2048][2048][2];
int sp[2048][2];

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",x+i),x[i]--;
	fore(i,0,n)sp[i+1][0]=sp[i][0],sp[i+1][1]=sp[i][1],sp[i+1][x[i]]++;
	fore(i,0,n+1){
		fore(j,i+1,n+1){
			if(x[j-1]==0){
				w[i][j][0]=w[i][j-1][0]+1;
				w[i][j][1]=w[i][j-1][1];
			}
			else {
				w[i][j][0]=w[i][j-1][0];
				w[i][j][1]=w[i][j-1][1]+1;
			}
			w[i][j][0]=max(w[i][j][0],w[i][j][1]);
		}
	}
	int r=0;
	fore(i,0,n+1)fore(j,i,n+1)r=max(r,sp[i][0]+w[i][j][0]+sp[n][1]-sp[j][1]);
	printf("%d\n",r);
	return 0;
}