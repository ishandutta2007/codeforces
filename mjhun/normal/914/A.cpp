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
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

set<int> w;

int main(){
	fore(i,0,1024)w.insert(i*i);
	int n;
	scanf("%d",&n);
	int r=-(1<<30);
	fore(i,0,n){
		int k;
		scanf("%d",&k);
		if(!w.count(k))r=max(r,k);
	}
	printf("%d\n",r);
	return 0;
}