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
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxN = 100 + 5;

int n;
ll a[maxN];

int main(){

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	ll res=0;

	for (int i=1; i<=n; i++){
		
		if (i==1)
			res+= a[i];

		else
			res+= 1ll + (a[i]-1ll) * (ll)i;
	}

	cout << res << endl;

	return 0;
}