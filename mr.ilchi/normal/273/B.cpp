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
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <iomanip>
#include <utility>

using namespace std;

typedef long long LL;
typedef complex<double> point;
typedef long double ldb;
typedef pair<int,int> pii;

int n,mod;
vector <pii> Q;

int main(){
	cin >> n;
	for (int i=0; i<n; i++){
		int temp; cin >> temp;
		Q.push_back(pii(temp,i));
	}
	for (int i=0; i<n; i++){
		int temp; cin >> temp;
		Q.push_back(pii(temp,i));
	}
	cin >> mod;
	sort(Q.begin(),Q.end());
	LL ans = 1;
	for (int i=0; i<(int)Q.size(); i++){
		int j=i;
		int past = -1;
		int p2 = 0;
		while (j<(int)Q.size() && Q[i].first==Q[j].first){
			if (Q[j].second == past)
				p2++;
			past = Q[j].second;
			j++;
		}
		for (int k=1; k<=(j-i); k++){
			int t2 = k;
			while (p2 && t2%2==0){
				t2/=2; p2--;
			}
			ans = (ans * t2) % mod;
		}
		i=j-1;
	}
	cout << ans << endl;
	return 0;
}