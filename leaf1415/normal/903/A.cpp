#include <iostream>

using namespace std;

int n;
bool can[105];

int main(void)
{
	int v;
	for(int i = 0; i <= 34; i++){
		for(int j = 0; j <= 15; j++){
			v = 3 * i + 7 * j;
			if(v > 100) continue;
			can[v] = true;
		}
	}
	
	cin >> n;
	
	int x;
	for(int i = 0; i < n; i++){
		cin >> x;
		if(can[x]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}