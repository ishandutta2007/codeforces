#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n, s, piso[1005] = {0},f,t;
	cin >> n >> s;
	while(n--){
		cin >> f >> t;
		if (piso[f] < t)
			piso[f] = t; 
	}

	int count = 0;
	for(int i = s; i > 0; i--, count ++)
		count = max( count, piso[i] );

	cout << count;

	return 0;
}