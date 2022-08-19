#include <iostream>
using namespace std;

int main() {
	string a;
	cin >> a;
	int n = a.size();
	for(int i = 1; 2*i < n; i++){
		int same = 1;
		for(int j = i; j < n; j++){
			if(a[j] != a[j-i]) same = 0;
		}
		if(same){
			cout << "YES" << endl;
			cout << a.substr(i) << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}