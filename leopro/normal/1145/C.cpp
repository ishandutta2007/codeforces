#include<iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int ans[16] = {15, 14, 12, 13, 8, 9, 10, 11, 0, 1, 2, 3, 4, 5, 6, 7,};
	cout << ans[n];
	return 0;
}