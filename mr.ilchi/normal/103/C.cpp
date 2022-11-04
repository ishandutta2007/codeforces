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

ll n,k,p;

inline ll bs (){
	
	ll s=0 , e = (k-1)/2 , res=0;

	while (s<=e){

		ll mid = (s+e)/2;

		ll siz = 2*mid;

		ll tool = 1 + 2*siz + (k-siz-1);

		if ((n-tool+1)%2==1)
			break;

		if (tool<=n){
			res = siz;
			s = mid+1;
		}

		else
			e = mid-1;
	}

	s=0 , e = (k-1)/2;

	if (2*e+1 > k-1)
		e--;

	while (s<=e){

		ll mid = (s+e)/2;

		ll siz = 2*mid + 1;

		ll tool = 1 + 2*siz + (k-siz-1);

		if ((n-tool+1)%2==1)
			break;

		if (tool<=n){
			res = siz;
			s = mid+1;
		}

		else
			e = mid-1;
	}

	return res;
}

int main(){

	cin >> n >> k >> p;

	if (k==n || k==0){		
		for (int i=1; i<=p; i++){
			if (k==n)
				cout << 'X';
			else
				cout << '.';
		}
		cout << endl;
		return 0;
	}

	ll res= bs();

	ll tool = 1 + 2*res + (k-res-1);

	ll start = n-tool+1;
	
	for (int i=1; i<=p; i++){
		
		ll pos; cin >> pos;

		if (pos<start){
			cout << '.';
			continue;
		}

		if (pos==start){
			cout << 'X';
			continue;
		}

		if (pos<start+2*res+1){
			
			if (pos%2==start%2)
				cout << 'X';
			else
				cout << '.';

			continue;
		}

		else
			cout << 'X';
	}

	cout << endl;

	return 0;
}