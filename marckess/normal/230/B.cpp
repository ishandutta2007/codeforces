#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	vector<bool> criba(1000005,true);

	criba[0] = criba[1] = false;
	for(int i = 2; i*i <= 1000000; i++)
		if(criba[i])
			for(int j = i*i; j <= 1000000; j += i )
				criba[j] = false;

	int n;
	long long x;

	cin >> n;
	while(n--){
		cin >> x;
		long long aux = sqrt(x);
		if ( aux * aux == x && criba[aux] )
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}

	return 0;
}