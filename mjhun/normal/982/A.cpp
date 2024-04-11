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

int n;char s[1024];

int main(){
	scanf("%d%s",&n,s);
	fore(i,0,n-1)if(s[i]=='1'&&s[i+1]=='1'){puts("No");return 0;}
	fore(i,0,n)if(s[i]=='0'&&(i==0||s[i-1]=='0')&&(i==n-1||s[i+1]=='0')){puts("No");return 0;}
	puts("Yes");
	return 0;
}