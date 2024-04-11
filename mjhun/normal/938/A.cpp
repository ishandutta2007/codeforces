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

bool v[256];
char s[128];int n;

int main(){
	v['a']=v['e']=v['i']=v['o']=v['u']=v['y']=true;
	scanf("%d%s",&n,s);
	for(int i=0;s[i];++i){
		if(i==0||!v[s[i]]||!v[s[i-1]])putchar(s[i]);
	}
	puts("");
	return 0;
}