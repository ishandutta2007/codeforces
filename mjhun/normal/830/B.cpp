#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

#define MAXN 100005

int ft[MAXN+1]; // for more dimensions, make ft multi-dimensional
void upd(int i0, int v){ // add v to i0th element (0-based)
	// add extra fors for more dimensions
	for(int i=i0+1;i<=MAXN;i+=i&-i)ft[i]+=v;
}
int get(int i0){ // get sum of range [0,i0)
	int r=0;
	// add extra fors for more dimensions
	for(int i=i0;i;i-=i&-i)r+=ft[i];
	return r;
}
int get(int i0, int i1){ // get sum of range [i0,i1) (0-based)
	return get(i1)-get(i0);
}

int n;
set<int> x[100005];

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		int k;
		scanf("%d",&k);k--;
		x[k].insert(i);
	}
	fore(i,0,n)upd(i,1);
	ll r=0;int k=0;
	fore(i,0,100005){
		while(!x[i].empty()){
			auto it=x[i].lower_bound(k);
			if(it==x[i].end()){
				it=x[i].begin();
				r+=get(k,n);
				r+=get(0,*it+1);
			}
			else {
				r+=get(k,*it+1);
			}
			upd(*it,-1);
			k=(*it+1)%n;
			x[i].erase(it);
		}
	}
	printf("%lld\n",r);
	return 0;
}