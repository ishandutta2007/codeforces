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


int n;
char s[100005];
int q[256],c=-1;

int main(){
	scanf("%d%s",&n,s);
	sort(s,s+n);
	puts(s);return 0;
	fore(i,0,n)q[s[i]]++;
	fore(i,'a','z'+1)if(q[i]%2==1)putchar(i);
	fore(i,'a','z'+1)fore(_,0,q[i]/2)putchar(i);
	for(int i='z';i>=0;--i)fore(_,0,q[i]/2)putchar(i);
	puts("");
	return 0;
}