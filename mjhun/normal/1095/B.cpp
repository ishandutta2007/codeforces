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

int n,a[100005];
multiset<int> w;

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",a+i),w.insert(a[i]);
	int r=1<<30;
	fore(i,0,n){
		w.erase(w.find(a[i]));
		r=min(r,*w.rbegin()-*w.begin());
		w.insert(a[i]);
	}
	printf("%d\n",r);
	return 0;
}