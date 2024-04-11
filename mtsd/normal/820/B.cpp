#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

int main(){
	int n,a;
	cin >> n >> a;
	double x;
	int ans;
	double err=10000.000;
	for(int i=2;i<=(n-1);i++){
		x = 180.0 - 180.0*(double)i/(double)n;
		if(err>abs(x-(double)a)){
			err = abs(x-(double)a);
			ans = i;
		}
	}
	cout << 1 << " " << 2 << " " << 1+ans << endl;
	return 0;
}