#include <iostream>
#include <string>

using namespace std;

int h, w;
int a[505][505];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w;
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			cin >> a[i][j];
		}
	}
	
	int sum = 0;
	for(int i = 1; i <= h; i++) sum ^= a[i][1];
	if(sum > 0){
		cout << "TAK" << endl;
		for(int i = 1; i <= h; i++) cout << 1 << " "; cout << endl;
		return 0;
	}
	
	for(int i = 1; i <= h; i++){
		for(int j = 2; j <= w; j++){
			if(a[i][j] != a[i][1]){
				cout << "TAK" << endl;
				for(int k = 1; k <= h; k++){
					if(i == k) cout << j << " ";
					else cout << 1 << " ";
				}
				cout << endl;
				return 0;
			}
		}
	}
	cout << "NIE" << endl;
	return 0;
}