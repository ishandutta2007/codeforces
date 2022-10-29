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

char s[200005];
int q[256];
vector<int> z;
string w;

int main(){
	scanf("%s",s);
	for(int i=0;s[i];++i)q[s[i]]++;
	fore(i,'a','z'+1)if(q[i]%2)z.pb(i);
	fore(i,0,SZ(z)/2)q[z[i]]++,q[z[SZ(z)-1-i]]--;
	fore(i,'a','z'+1)fore(_,0,q[i]/2)w.pb(i);
	printf("%s",w.c_str());
	if(SZ(z)%2)putchar(z[SZ(z)/2]);
	reverse(w.begin(),w.end());
	puts(w.c_str());
	return 0;
}