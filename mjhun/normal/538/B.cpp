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

int main(){
	int n;
	scanf("%d",&n);
	vector<int> r;
	while(n){
		int m=n,t=0,c=1;
		while(m){
			if(m%10)t+=c,n-=c;
			m/=10;
			c*=10;
		}
		r.pb(t);
	}
	printf("%d\n",SZ(r));
	fore(i,0,SZ(r))printf("%d%c",r[i]," \n"[i==SZ(r)-1]);
	return 0;
}