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
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

char s[5005];int n;
vector<int> w[32];
int q[32];

int main(){
	scanf("%s",s);n=strlen(s);
	fore(i,0,n)s[i]-='a';
	fore(i,0,n)w[s[i]].pb(i);
	int r=0;
	fore(i,0,26){
		if(!SZ(w[i]))continue;
		int ss=0;
		fore(j,1,n){
			mset(q,0);
			for(int x:w[i])q[s[(x+j)%n]]++;
			int t=0;
			fore(k,0,26)if(q[k]==1)t++;
			ss=max(ss,t);
		}
		r+=ss;
	}
	printf("%.12lf\n",1.*r/n);
	return 0;
}