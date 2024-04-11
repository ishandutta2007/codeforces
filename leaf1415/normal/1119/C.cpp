#include <iostream>

using namespace std;

int h, w;
int a[505][505], b[505][505], c[505][505];

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
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			cin >> b[i][j];
		}
	}
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			c[i][j] = (a[i][j]^b[i][j])&1;
		}
	}
	
	for(int i = 1; i <= h; i++){
		int sum = 0;
		for(int j = 1; j <= w; j++){
			sum += c[i][j];
		}
		if(sum%2){
			cout << "No" << endl;
			return 0;
		}
	}
	for(int j = 1; j <= w; j++){
		int sum = 0;
		for(int i = 1; i <= h; i++){
			sum += c[i][j];
		}
		if(sum%2){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	
	return 0;
}