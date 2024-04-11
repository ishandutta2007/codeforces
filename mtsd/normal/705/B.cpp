#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	int n,a,sum;
	sum =0;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a;
		a -=1;
		sum=sum+(a%2);
		if(sum%2)cout << 1 <<endl;
		else cout << 2 <<endl;
	}
	return 0;
}