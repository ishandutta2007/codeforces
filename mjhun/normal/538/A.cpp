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

string t="CODEFORCES";
string s;

int main(){
	cin>>s;
	if(SZ(s)<SZ(t)){puts("NO");return 0;}
	int k0=0;
	while(k0<SZ(t)&&t[k0]==s[k0])k0++;
	int k1=0;
	while(k1<SZ(t)&&t[SZ(t)-1-k1]==s[SZ(s)-1-k1])k1++;
	if(k0+k1>=SZ(t))puts("YES");
	else puts("NO");
	return 0;
}