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

const int maxN = 100*1000 + 5;

int n,k;
char a[maxN];

int main(){

	ios_base::sync_with_stdio(false);

	cin >> n >> k;

	for (int i=1; i<=n; i++)
		cin >> a[i];

	int poi=1;

	for (int i=1; i<=k; i++){

		while (poi<n && (a[poi]!='4' || a[poi+1]!='7')) poi++;

		if (poi==n)
			break;

		if (poi%2==0){
			
			if (a[poi-1]=='4'){

				if ((k-i+1)%2==1)
					a[poi] = '7';

				break;
			}
			else{
				a[poi] = '7'; poi++;
			}
		}

		else{
			a[poi+1] = '4'; poi++;
		}
	}

	for (int i=1; i<=n; i++)
		cout << a[i]; cout << endl;

	return 0;
}