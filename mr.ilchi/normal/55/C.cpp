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
 */

#include <iostream>

using namespace std;

int n, m, k;

int main (){
	cin >> n >> m >> k;
	for (int i= 1;i<= k;i ++){
		int x, y;
		cin >> x >> y;
		if (min (min (x-1, n-x), min (y-1, m-y)) <= 4){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;

	return 0;
}