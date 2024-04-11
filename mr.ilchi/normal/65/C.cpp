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
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ldb;

const int maxN= 10000+5;
const int BASE= 10000000;
const ldb eps = 1e-12;

ll n, v1, v2;

struct triple{
	ll x,y,z;
	
	triple (ll _x=-1, ll _y=-1, ll _z=-1) : x(_x), y(_y), z(_z) {}

	inline void read(){
		cin >> x >> y >> z;
	}

	inline triple operator + (const triple &sec) const{
		return triple (x+sec.x, y+sec.y, z+sec.z);
	}

	inline void operator *= (const int &v){
		x*=v; y*=v; z*=v;
	}

	inline void operator /= (const int &v){
		x/=v; y/=v; z/=v;
	}

	inline bool operator == (const triple &sec) const{
		return (x==sec.x) && (y==sec.y) && (z==sec.z);
	}


}a[maxN];
triple beg, res;
/*****************************************/
inline ldb dis (triple &a1, triple &a2){
	return sqrt (pow((ldb)a1.x-a2.x,2) + pow((ldb)a1.y-a2.y,2) + pow((ldb)a1.z-a2.z,2));
}
/*****************************************/
inline void bsearch(ll End, ldb past){
	triple s= a[End-1], e= a[End];
	a[End-1]*= BASE; a[End]*=BASE;
	s *= BASE; e*= BASE; beg*= BASE; past*= BASE;
	v1*=BASE ; v2*=BASE;

	res=e; 

	while (s.x!=e.x || s.y!=e.y || s.z!=e.z){
		triple mid= (s+e); mid/=2;
		if (mid==s || mid==e){
			break;
		}

		ldb dis1= dis (beg, mid);
		ldb dis2= dis (a[End-1], mid) + past;

		if ((dis1/v1 - dis2/v2)<eps)
			res= e= mid;
		else
			s= mid; 
	}
}
/*****************************************/
int main(){
	cin >> n;
	n++;
	for (int i=1;i<=n;i++)
		a[i].read();
	
	cin >> v1 >> v2;

	beg.read();

	ll End=-1;
	ldb past=0;
	for (int i=1;i<=n;i ++){
		ldb tmp= dis (beg, a[i]);
		if ((tmp/v1 - past/v2)<eps){
			End= i;
			break;
		}
		past+= dis(a[i],a[i+1]);
	}

	if (End==-1){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	cout << fixed << setprecision(6);
	if (End==1){
		cout << (ldb)0<< endl;
		cout << (ldb)a[1].x << ' ' << (ldb)a[1].y << ' ' << (ldb)a[1].z << endl;
		return 0;
	}
		
	bsearch (End, past - dis(a[End-1],a[End]));
	
	cout << dis(res,beg)/v1 << endl << (ldb)res.x/BASE << ' ' << (ldb)res.y/BASE << ' ' << (ldb)res.z/BASE << endl;

	return 0;
}