#include <iostream>

using namespace std;

int main(){
	int a100 = 0, a200 = 0, a, n;

	cin >> n;
	while (n--){
		cin >> a;
		if (a == 100)
			a100++;
		else
			a200++;
	}

	if ( a100 > 0 && a100 % 2 == 0 )
		cout << "YES";
	else if ( a100 == 0 && a200 % 2 == 0 )
		cout << "YES";
	else
		cout << "NO";

	return 0;
}