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
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int a,b,n;

int main(){
	cin >> a >> b;
	cin >> n;

	vector <int> Q;
	for (int i=1;i*i<=a;i++) if (a%i==0){
		Q.push_back (i);
		if (i*i!=a)
			Q.push_back (a/i);
	}

	for (int i=1;i*i<=b;i++) if (b%i==0){
		Q.push_back (i);
		if (i*i!=b)
			Q.push_back (b/i);
	}

	sort (Q.begin(), Q.end());

	vector <int> com;

	for (int i=1;i<(int)Q.size();i++){
		if (Q[i]==Q[i-1])
			com.push_back (Q[i]);
	}

	for (int i=1;i<=n;i++){
		int low, high; cin >> low >> high;

		vector <int> :: iterator f= lower_bound (com.begin(), com.end(), low);
		vector <int> :: iterator e= upper_bound (com.begin(), com.end(), high);

		if (f==com.end()){
			cout << -1 << endl;
			continue;
		}

		if (*f > high){
			cout << -1 << endl;
			continue;
		}

		if (e==com.end()){
			cout << com.back () << endl;
			continue;
		}

		cout << *(--e) << endl;
	}

	return 0;
}