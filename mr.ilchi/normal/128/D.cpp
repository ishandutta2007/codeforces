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
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxN = 100*1000 + 5;

int n;
int a[maxN];

int main(){

	ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i=1; i<=n; i++)
		cin >> a[i];

	sort (a+1, a+n+1);

	for (int i=2; i<=n; i++) if (a[i]-a[i-1]>1){
		cout << "NO" << endl;
		return 0;
	}

	vector <int> Q;

	int past = a[1]-1 , tedad = 0;

	for (int i=1; i<=n; i++){
		
		if (a[i]==past)
			tedad++;

		else{
			if (tedad>0)
				Q.push_back (tedad);
			tedad = 1;
			past  = a[i];
		}
	}

	if (tedad>0)
		Q.push_back (tedad);

	for (int i=0; i<(int)Q.size(); i++) 
		Q[i]*=2;

	for (int i=0; i<(int)Q.size()-1; i++){
		
		if (Q[i]<=0){
			cout << "NO" << endl;
			return 0;
		}

		Q[i+1]-=Q[i];
	}

	if (Q.back()!=0){
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;
		
	return 0;
}