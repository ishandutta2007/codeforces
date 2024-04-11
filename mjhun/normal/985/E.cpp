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

int n,k,d,a[1<<19];
set<int> w;

int main(){
	scanf("%d%d%d",&n,&k,&d);
	fore(i,0,n)scanf("%d",a+i);
	sort(a,a+n);
	w.insert(n);
	for(int i=n-1;i>=0;--i){
		auto it=w.lower_bound(i+k);
		if(it!=w.end()&&a[*it-1]-a[i]<=d)w.insert(i);
	}
	puts(w.count(0)?"YES":"NO");
	return 0;
}