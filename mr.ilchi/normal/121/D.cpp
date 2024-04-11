/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <complex>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef complex<double> point;
typedef pair<ll,ll> pll;

const int maxN = 100*1000 + 5;
const ll  inf  = (1ll<<60);

ll n,k;
ll back[1<<20],front[1<<20];
vector <ll> Q;

struct node{
	
	ll s,e;

	node () {}

	node (ll s, ll e) : s(s) , e(e) {}

}a[maxN],b[maxN];

inline bool cmp1 (const node &a1 , const node &a2){	
	return a1.s<a2.s;
}

inline bool cmp2 (const node &a1 , const node &a2){
	return a1.e<a2.e;
}

inline void go (int pos , ll val){
	
	if (pos!=0)
		Q.push_back (val);

	if (pos==19)
		return;

	go (pos+1, val*10 + 4);
	go (pos+1, val*10 + 7);
}

inline void setDyn (){

	int poi=n;
	
	for (int i=(int)Q.size()-1; i>=0; i--) if (Q[i]<(1ll<<60)){

		if (poi!=n){			
			if ((Q[i+1]-Q[i]) > inf/(n-poi)){
				front[i] = k+1;
			}
			else
				front[i] = min (k+1 , (Q[i+1]-Q[i]) * (n-poi) + front[i+1]); 
		}

		while (poi>0 && a[poi].s>Q[i]) { front[i]+= (a[poi].s-Q[i]); front[i] = min (front[i],k+1); poi--; } 		
	}

	poi = 1;

	for (int i=0; i<(int)Q.size(); i++) if (Q[i]<(1ll<<60)){

		if (poi!=1){
			if ((Q[i]-Q[i-1]) > inf/(poi-1))
				back[i] = k+1;
			else
				back[i] = min (k+1 , (Q[i]-Q[i-1]) * (poi-1) + back[i-1]);
		}

		while (poi<=n && b[poi].e<Q[i]) { back[i]+= (Q[i]-b[poi].e); back[i] = min (k+1,back[i]); poi++; }
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	
	go (0,0ll); sort (Q.begin() , Q.end());

	cin >> n >> k;

	ll minLen = (1ll<<60);

	for (int i=1; i<=n; i++){
		cin >> a[i].s >> a[i].e;
		b[i] = a[i];
		minLen = min (minLen , a[i].e - a[i].s + 1);
	}

	sort (a+1 , a+n+1 , cmp1);
	sort (b+1 , b+n+1 , cmp2);

	ll ans = 0;

	setDyn();

	for (int i=0; i<(int)Q.size(); i++) if (Q[i]<(1ll<<60)){

		ll beg=i , fin=(int)Q.size()-1;

		while (beg<=fin){
			
			ll mid = (beg+fin)/2;

			if (Q[mid]-Q[i]+1 > minLen){
				fin = mid-1; continue;
			}

			ll cost = front[beg] + back[mid];

			if (cost<=k){
				ans = max (ans , mid-i+1); beg = mid+1;
			}
			else
				fin = mid-1;
		}
	}

	cout << ans << endl;

	return 0;
}