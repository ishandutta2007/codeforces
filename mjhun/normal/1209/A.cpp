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

int n,a[128];
bool v[128];

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",a+i);
	sort(a,a+n);
	int r=0;
	fore(i,0,n)if(!v[i]){
		r++;
		fore(j,i+1,n)if(a[j]%a[i]==0)v[j]=true;
	}
	printf("%d\n",r);
	return 0;
}