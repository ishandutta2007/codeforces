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


char s[200005];int n,m;
vector<int> w[32];
int q[32];

int main(){
	scanf("%d%s%d",&n,s,&m);
	fore(i,0,n)w[s[i]-'a'].pb(i);
	while(m--){
		scanf("%s",s);
		mset(q,0);
		for(int i=0;s[i];++i)q[s[i]-'a']++;
		int r=0;
		fore(i,0,26)if(q[i])r=max(r,w[i][q[i]-1]+1);
		printf("%d\n",r);
	}
	return 0;
}