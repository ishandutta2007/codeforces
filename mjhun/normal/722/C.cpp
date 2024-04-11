#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

set<int> e;
multiset<ll> w;
int a[100005];
ll s[100005];
int n;

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		scanf("%d",a+i);
	}
	s[0]=0;
	fore(i,1,n+1){
		s[i]=s[i-1]+a[i-1];
	}
	w.insert(-s[n]);
	e.insert(-1);e.insert(n);
	fore(i,0,n){
		int p;
		scanf("%d",&p);p--;
		int l,r;
		set<int>::iterator it=e.upper_bound(p);
		r=*it;
		--it;
		l=*it+1;
		w.erase(w.find(-(s[r]-s[l])));
		w.insert(-(s[p]-s[l]));
		w.insert(-(s[r]-s[p+1]));
		e.insert(p);
		printf("%I64d\n",-(*w.begin()));
	}
	return 0;
}