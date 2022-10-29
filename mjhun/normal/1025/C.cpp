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
int n;

int main(){
	scanf("%s",s);n=strlen(s);
	fore(i,0,n)s[i+n]=s[i];
	int t=1,r=1;
	fore(i,1,2*n){
		if(s[i]!=s[i-1])t++;
		else t=1;
		r=max(r,t);
	}
	printf("%d\n",min(r,n));
	return 0;
}