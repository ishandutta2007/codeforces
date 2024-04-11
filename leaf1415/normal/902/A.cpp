#include <iostream>

using namespace std;

int n, m;
bool can[105];

int main(void)
{
	cin >> n >> m;
	int a, b;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		for(int j = a; j < b; j++) can[j] = true;
	}
	
	for(int i = 0; i < m; i++){
		if(!can[i]){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}