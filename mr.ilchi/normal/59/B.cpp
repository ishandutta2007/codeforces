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
#include <string>
#include <algorithm>

using namespace std;

const int maxN= 100+5;

int n;
int a[maxN];

int main(){
	cin >> n;
	int sum=0;
	for (int i=1;i<= n;i ++){
		cin >> a[i];
		sum+= a[i];
	}
	if (sum&1){
		cout << sum << endl;
		return 0;
	}		
	sort (a+1, a+n+1);
	for (int i=1;i<= n;i ++)
		if (a[i]&1){
			cout << sum-a[i] << endl;
			return 0;
		}
	cout << 0 << endl;
	return 0;
}