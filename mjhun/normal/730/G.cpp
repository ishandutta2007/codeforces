#include <bits/stdc++.h>
#define snd second
#define pb push_back
#define fst first
#define mp make_pair
#define fore(i,a,n) for(int i = a, qwer = n;i<qwer;i++)

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const int N = 100500;
ii a[N];
int main() {
	int n;
	scanf("%d",&n);
	fore(i,0,n)
		scanf("%lld%lld",&a[i].fst,&a[i].snd);
	set<ii> s;
	s.insert(mp(1LL<<60,1LL<<60));
	fore(i,0,n) {
		ll c = a[i].fst;
		ll f = c+a[i].snd-1LL;
		ii p = *s.lower_bound(ii(c,0));
		if(f < p.snd) {
			printf("%lld %lld\n",c,f);
			s.insert(ii(f,c));
		} else {
			for(set<ii>::iterator it = s.begin();it != s.end();it++) {
				p = *it;
				if(p.snd - a[i].snd > 0 && (*s.lower_bound(ii(p.snd-a[i].snd,0))).snd >= p.snd) {
					//cerr << p.fst << " " << p.snd << endl;
					if(it == s.begin()) {
						printf("1 %lld\n",a[i].snd);
						s.insert(ii(a[i].snd,1));
					} else {
						it--;
						ll k = (*it).fst;
						printf("%lld %lld\n",k+1,k+a[i].snd);
						s.insert(ii(k+a[i].snd,k+1));
					}
					break;
				}
			}
		}
	
	}
	return 0;
}