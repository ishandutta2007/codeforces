#include <iostream>

using namespace std;

int T;

int main(void)
{
	cin >> T;
	int ang;
	for(int t = 0; t < T; t++){
		cin >> ang;
		
		if(ang == 180){
			cout << -1 << endl;
			continue;
		}
		if(ang == 179){
			cout << 360 << endl;
			continue;
		}
		
		for(int n = 3; n <= 179; n++){
			for(int k = 1; k <= n-2; k++){
				if(180*k%n) continue;
				if(180*k/n == ang){
					cout << n << endl;
					goto end;
				}
			}
		}
		cout << 180 << endl;
		end:;
	}
	
	return 0;
}