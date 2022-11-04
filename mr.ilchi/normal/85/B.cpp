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
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

typedef pair<int,int> pii;
typedef long double ldb;
typedef long long ll;

const int maxN= 100*1000 + 5;

int k[5];
int t[5];
int n;
ll c[maxN], x[maxN];

int main(){
	
	for (int i=1;i<=3;i++)
		cin >> k[i];
	for (int i=1;i<=3;i++)
		cin >> t[i];

	cin >> n;

	for (int i=1;i<=n;i++){
		cin >> c[i];
		x[i]= c[i];
	}

	for (int i=1;i<=3;i++){
		
		if (k[i]>=n){
			for (int j=1;j<=n;j++)
				c[j]+= t[i];
		}

		else{

			for (int j=1;j<=n;j++){

				if (j<=k[i])
					c[j]+= t[i];

				else
					c[j]= max (c[j-k[i]], c[j]) + t[i];
			}
		}
	}

	ll res= -1;

	for (int i=1;i<=n;i++)
		res= max (res, c[i] - x[i]);

	cout << res << endl;

	return 0;
}