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
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

struct node{

	int x,y,id;

	node () {}

	node (int x, int y) : x(x) , y(y) {}

	inline bool operator < (const node &sec) const{
	
		return (x!=sec.x) ? x<sec.x : y<sec.y;
	}

}p[20];	

inline int p2 (int x){
	return x*x;
}

inline int dis (node a , node b){
	
	return p2(a.x - b.x) + p2(a.y - b.y);
}

inline bool rec (int mask){

//	cout << mask << endl;

	node t[4];

	int cnt = 0;

	for (int i=0; i<8; i++) if (mask & (1<<i))
		t[cnt++] = p[i];

	int a1 = dis(t[0],t[1]);
	int a2 = dis(t[0],t[2]);
	int b1 = dis(t[3],t[1]);
	int b2 = dis(t[3],t[2]);
	int c1 = dis(t[0],t[3]);
	int c2 = dis(t[1],t[2]);

	if (a1!=b2 || a2!=b1 || c1!=c2 || a1+a2!=c1)
		return false;

	node m1 = node ((t[0].x + t[3].x) / 2 , (t[0].y + t[3].y) / 2); 
	node m2 = node ((t[1].x + t[2].x) / 2 , (t[1].y + t[2].y) / 2);

	return (m1.x==m2.x) && (m1.y==m2.y);

}

inline bool sq (int mask){
	
	node t[4];

	int cnt = 0;

	for (int i=0; i<8; i++) if (mask & (1<<i))
		t[cnt++] = p[i];

/*	cout << t[0].x << ' ' << t[0].y << endl;
	cout << t[1].x << ' ' << t[1].y << endl;
	cout << t[2].x << ' ' << t[2].y << endl;
	cout << t[3].x << ' ' << t[3].y << endl;
*/
//	cout << ":D" << mask << endl;

	int a1 = dis(t[0],t[1]);
	int a2 = dis(t[0],t[2]);
	int b1 = dis(t[3],t[1]);
	int b2 = dis(t[3],t[2]);
	int c1 = dis(t[0],t[3]);
	int c2 = dis(t[1],t[2]);

	if (a1!=a2 || a1!=b1 || a1!=b2 || c1!=c2 || 2*a1!=c1)
		return false;

//	cout << ":D" << endl;

	node m1 = node ((t[0].x + t[3].x) / 2 , (t[0].y + t[3].y) / 2); 
	node m2 = node ((t[1].x + t[2].x) / 2 , (t[1].y + t[2].y) / 2);

	return (m1.x==m2.x) && (m1.y==m2.y);
}

int main(){

	for (int i=0; i<8; i++){
		cin >> p[i].x >> p[i].y; p[i].id = i+1;
		p[i].x*=2; p[i].y*=2;
	}

	sort (p, p+8);

	for (int i=0; i<(1<<8); i++) if (__builtin_popcount(i)==4){
		
		if (sq(i) && rec(((1<<8)-1)^i)){
			cout << "YES" << endl;
			for (int j=0; j<8; j++) if (i & (1<<j))
				cout << p[j].id << ' ';
			cout << endl;
			for (int j=0; j<8; j++) if (!(i&(1<<j)))
				cout << p[j].id << ' ';
			cout << endl;
			return 0;
		}
//		else
//			break;
	}

	cout << "NO" << endl;

	return 0;
}