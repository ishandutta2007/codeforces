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

int n,k;
int p[3005];

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",p+i);
	fore(i,0,n)fore(j,i+1,n)if(p[i]>p[j])k++;
	printf("%d\n",k%2+4*(k/2));
	return 0;
}