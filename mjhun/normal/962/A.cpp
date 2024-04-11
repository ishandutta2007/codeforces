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

int a[200005],s,n;

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		scanf("%d",a+i);s+=a[i];
	}
	int t=0;
	fore(i,0,n){
		t+=a[i];
		if(t*2>=s){printf("%d\n",i+1);return 0;}
	}
	assert(0);
	return 0;
}