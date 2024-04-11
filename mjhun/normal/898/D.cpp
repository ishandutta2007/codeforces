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

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order(i) -> iterator to ith element
// order_of_key(k) -> position (int) of lower_bound of k

ordered_set w;

int main(){
	int k,n,m;
	scanf("%d%d%d",&n,&m,&k);k--;
	fore(_,0,n){
		int a;
		scanf("%d",&a);
		w.insert(a);
	}
	int r=0;
	for(int i=0;i<(1<<20);++i){
		int z=w.order_of_key(i+m)-w.order_of_key(i);
		r+=max(z-k,0);
		fore(_,0,max(z-k,0)){
			auto it=w.lower_bound(i+m);--it;
			w.erase(it);
		}
	}
	printf("%d\n",r);
	return 0;
}