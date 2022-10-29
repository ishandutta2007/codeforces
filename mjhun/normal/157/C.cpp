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

char s[6015],t[2015];

int main(){
	scanf("%s%s",s+2002,t);
	int r=1<<30,n=strlen(t);
	fore(i,0,6015-n){
		int w=0;
		fore(j,0,n)w+=s[i+j]!=t[j];
		r=min(r,w);
	}
	printf("%d\n",r);
	return 0;
}