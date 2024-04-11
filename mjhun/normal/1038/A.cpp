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

char s[100005];
int q[32];
int n,k;

int main(){
	scanf("%d%d%s",&n,&k,s);
	fore(i,0,n)q[s[i]-'A']++;
	int t=1<<30;
	fore(i,0,k)t=min(t,q[i]);
	int r=n;
	fore(i,0,k)r-=q[i]-t;
	printf("%d\n",r);
	return 0;
}