#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>
#define ll long long
#define vi vector<bool>

using namespace std;

int main(){
	int a, b, c, d, res;
	cin >> a >> b >> c >> d;
	bool f = true, f1 = false;

	int k = 0;
	while(f){
		int x = b + k * a;
		if ( x - d >= 0 && (x - d) % c == 0 ){
			f = false;
			break;
		}
		if ( x - d >= 0 ){
		if ( f1 ){
			if ( res == (x - d) % c )
				break;
		}else{
			res = (x - d) % c;
			f1 = true;
		}
	}
	k++;
	}

	if ( f )
		cout << -1;
	else
		cout << b + k * a;

	return 0;
}