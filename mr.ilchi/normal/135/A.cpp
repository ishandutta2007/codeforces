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

const int maxN = 100*1000 + 5;

int n;
int a[maxN];

int main(){
	
	ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i=1; i<=n; i++)
		cin >> a[i];

	if (n==1){

		if (a[1]!=1)
			cout << 1 << endl;
		else
			cout << 2 << endl;

		return 0;
	}

	sort (a+1 , a+n+1);

	cout << 1 << ' ';

	for (int i=2; i<=n; i++){

		if (a[i]==1){
			if (i==n)
				cout << 2 << ' ';
			else
				cout << 1 << ' ' ;
		}

		else
			cout << a[i-1] << ' ';
	}

	cout << endl;

	return 0;
}