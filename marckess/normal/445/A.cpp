#include <iostream>

using namespace std;

int main(){
	int n, m;

	cin >> n >> m;

	char c;
	for(int i = 0; i < n; i++){
		bool p = i % 2;
		for(int j = 0; j < m; j++, p = !p ){
			cin >> c;
			if ( c == '-' )
				cout << c;
			else if (p)
				cout << "B";
			else
				cout << "W";
		}
		cout << endl;
	}

	return 0;
}