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

vector<int> w[100005];
int r[100005];
int n;

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		int a;
		scanf("%d",&a);
		w[n-a].pb(i);
	}
	int c=1;
	fore(i,1,n+1){
		if(SZ(w[i])%i){puts("Impossible");return 0;}
		for(int j=0;j<SZ(w[i]);j+=i){
			fore(k,j,j+i)r[w[i][k]]=c;
			c++;
		}
	}
	puts("Possible");
	fore(i,0,n)printf("%d%c",r[i]," \n"[i==n-1]);
	return 0;
}