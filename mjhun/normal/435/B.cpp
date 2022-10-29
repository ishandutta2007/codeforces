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

char s[32];int n,k;

int main(){
	scanf("%s%d",s,&k);n=strlen(s);
	int i=0;
	while(i<n&&k){
		int t=max_element(s+i,s+min(n,i+k+1))-s;
		for(int j=t;j>i;--j)swap(s[j],s[j-1]);
		k-=t-i;
		i++;
	}
	puts(s);
	return 0;
}