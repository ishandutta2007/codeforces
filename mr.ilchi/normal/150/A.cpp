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
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <complex>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;

ll q;

int main(){
	
	cin >> q;

	if (q==1){
		cout << 1 << endl <<  0 << endl;
		return 0;
	}

	vector <ll> prime;
	vector <int> tedad;

	ll p = q;

	int tot = 0;

	for (ll i=2; i*i<=q; i++){
		
		int cnt = 0;
		while (q%i==0){
			q/=i; cnt++;
		}
		if (cnt){
			prime.push_back (i);
			tedad.push_back (cnt);
		}
		tot+= cnt;
	}

	if (q>1){
		tot++;
		prime.push_back (q);
		tedad.push_back (1);
	}

	if (tot==2){
		cout << 2 << endl;
		return 0;
	}

	if (tot==1){
		cout << 1 << endl << 0 << endl;
		return 0;
	}

	ll now = 1;

	int pw=2;

	for (int i=0; i<prime.size(); i++){
		
		while (tedad[i] && pw){
			now*= prime[i];
			tedad[i]--; pw--;
		}
	}

	cout << 1 << endl << now << endl;

	return 0;
}