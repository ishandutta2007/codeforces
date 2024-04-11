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

int a[100005],p[100005];
bool r[100005];
int n;

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",a+i),a[i]--;
	fore(i,0,n)p[a[i]]=i;
	for(int i=n-1;i>=0;--i){
		r[p[i]]=false;
		for(int j=p[i]-(i+1);j>=0;j-=i+1)if(a[j]>i)r[p[i]]|=!r[j];
		for(int j=p[i]+(i+1);j<n;j+=i+1)if(a[j]>i)r[p[i]]|=!r[j];
	}
	fore(i,0,n)putchar(r[i]?'A':'B');
	puts("");
	return 0;
}