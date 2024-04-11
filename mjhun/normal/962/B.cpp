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

int n,a,b,r;
char s[200005];

int main(){
	scanf("%d%d%d%s",&n,&a,&b,s);
	int i=0;
	while(i<n){
		if(s[i]=='*'){i++;continue;}
		int j=i;
		while(j<n&&s[j]=='.')j++;
		int q=j-i;
		if(b>a)swap(a,b);
		int k=min(a,(q+1)/2);
		r+=k;a-=k;
		k=min(b,q/2);
		r+=k;b-=k;
		i=j+1;
	}
	printf("%d\n",r);
	return 0;
}