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
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <complex>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;

const int maxN = 100*1000 + 5;

int n;
pii a[maxN];

int main(){

	ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i=1; i<=n; i++){
		cin >> a[i].first; a[i].second = i;
	}

	sort (a+1 , a+n+1);

//	vector <pii> Q;

	set <pii> sit;

	for (int i=1; i<=n; i++){
		int cnt=0,j=i;
		while (j<=n && a[i].first==a[j].first){
			j++; cnt++;
		}
		sit.insert (pii(cnt,a[i].first));
		i=j-1;
	}

	vector <int> a,b,c;

	while ((int)sit.size() > 2){
		set <pii> :: iterator it = sit.end(); it--;
		pii a1=*it;it--;
		pii a2=*it;it--;
		pii a3=*it;
		a.push_back (a1.second);
		b.push_back (a2.second); 
		c.push_back (a3.second);

		sit.erase(a1); a1.first--;
		sit.erase(a2); a2.first--;
		sit.erase(a3); a3.first--;

		if (a1.first) sit.insert(a1);
		if (a2.first) sit.insert(a2);
		if (a3.first) sit.insert(a3);
	}

	cout << (int)a.size() << endl;

	for (int i=0; i<(int)a.size(); i++){
		int x=a[i];
		int y=b[i];
		int z=c[i];
		if (x<y) swap (x,y);
		if (x<z) swap (x,z);
		if (y<z) swap (y,z);
		cout << x << ' ' << y << ' ' << z << endl;
	}
	return 0;
}