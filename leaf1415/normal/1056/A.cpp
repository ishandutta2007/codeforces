#include <iostream>

using namespace std;

int n;
bool flag[105], tmp[105];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= 100; i++) flag[i] = true;
	for(int i = 0; i < n; i++){
		int r;
		cin >> r;
		for(int j = 1; j <= 100; j++) tmp[j] = false;
		for(int j = 0; j < r; j++){
			int a;
			cin >> a;
			tmp[a] = true;
		}
		for(int j = 1; j <= 100; j++) flag[j] &= tmp[j];
	}
	for(int i = 1; i <= 100; i++){
		if(flag[i]) cout << i << " ";
	}
	cout << endl;
	return 0;
}