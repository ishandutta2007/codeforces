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

int n,m;
int q[100005],x;

int main(){
	scanf("%d%d",&n,&m);
	fore(_,0,m){
		int t;
		scanf("%d",&t);
		t--;
		if(!q[t])x++;
		q[t]++;
		if(x==n){
			putchar('1');
			fore(i,0,n){
				q[i]--;
				if(!q[i])x--;
			}
		}
		else putchar('0');
	}
	puts("");
	return 0;
}