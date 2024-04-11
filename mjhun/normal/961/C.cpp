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

int n;
char b[1024];
int d0[4],d1[4];

int main(){
	scanf("%d",&n);
	fore(_,0,4){
		int d[2];d[0]=d[1]=0;
		fore(i,0,n){
			scanf("%s",b);
			fore(j,0,n){
				if(b[j]=='0')d[(i+j)%2]++;
				else d[1-(i+j)%2]++;
			}
		}
		//printf("%d %d\n",d[0],d[1]);
		d0[_]=d[0];
		d1[_]=d[1];
	}
	int r=1<<30;
	r=min(r,d0[0]+d0[1]+d1[2]+d1[3]);
	r=min(r,d0[0]+d1[1]+d0[2]+d1[3]);
	r=min(r,d0[0]+d1[1]+d1[2]+d0[3]);
	r=min(r,d1[0]+d0[1]+d0[2]+d1[3]);
	r=min(r,d1[0]+d0[1]+d1[2]+d0[3]);
	r=min(r,d1[0]+d1[1]+d0[2]+d0[3]);
	printf("%d\n",r);
	return 0;
}