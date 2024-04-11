/*
 * in the name of god
 *
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
#include <set>
#include <map>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <cstring>
#include <fstream>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef complex<double> point;

const int maxN = 100*1000 + 5;

int n;
pii a[maxN];

struct node{
	
	int x,y,id;

	node () {}

	node (int x , int y , int id) : x(x) , y(y) , id(id) {}

	inline bool operator < (const node &sec) const{
	
		return (x!=sec.x) ? x<sec.x : y<sec.y;
	}
}b[maxN];

struct cmp{

	inline bool operator () (const node &fir , const node &sec) const{
		return (fir.y!=sec.y) ? fir.y<sec.y : fir.x<sec.x;
	}
};	

inline int P2 (int x){
	
	return x*x;
}

inline int dis (pii x){
	
	if (x.first == -1)
		return (1ll<<30);

	return P2(b[x.first].x - b[x.second].x) + P2(b[x.first].y - b[x.second].y);
}

inline pii go (int l , int r){

	if (l==r)
		return pii(-1,-1);

	if (r-l==1)
		return pii(l,r);

	int mid = (l+r)/2;

	pii ret1 = go(l,mid);
	pii ret2 = go(mid+1,r);

	pii ret;

	if (dis(ret1)<dis(ret2))
		ret = ret1;
	else
		ret = ret2;

	int dist = (int)(sqrt(dis(ret))+1e-9);

	int poi = mid+1;

	set <node , cmp> sit;

	for (int i=l; i<=mid; i++){
		
		int maxx = b[i].x + dist; 

		while (poi<=r && b[poi].x<=maxx){
			sit.insert (node(b[poi].x,b[poi].y,poi)); poi++;
		}

		set <node,cmp> :: iterator it = sit.lower_bound (node(b[i].x,b[i].y-dist,-1));

		while ((it!=sit.end()) && ((it->y) <= b[i].y + dist)){
			
			if (dis(pii(i,it->id)) < dis(ret))
				ret = pii(i,it->id);

			it++;
		}
	}

	return ret;
}

inline int type (pii x){
	
	if (x.first >=0 && x.second>=0)
		return 1;
	if (x.first <0 && x.second>=0)
		return 2;
	if (x.first>=0 && x.second<0)
		return 3;
	return 4;
}

int main(){

	freopen ("input.txt"  , "r" , stdin);
	freopen ("output.txt"  , "w" , stdout);

	ios_base::sync_with_stdio(false);

	cin >> n;
	
	for (int i=1; i<=n; i++){
		cin >> a[i].first >> a[i].second;
		b[i] = node(labs(a[i].first) , labs(a[i].second) , i);
	}

	sort (b+1 , b+n+1);

	pii res = go (1,n);

	int f1 = b[res.first].id;
	int f2 = b[res.second].id;

	if (f1 > f2)
		swap (f1,f2);

	int ch1 = type(a[f1]);
	int ch2 = type(a[f2]);

	cout << f1 << ' ' << ch1 << ' ' << f2 << ' ' << 5-ch2 << endl;

	return 0;
}