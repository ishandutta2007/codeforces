#include <iostream>

using namespace std;

int main(){
	int n, pts[205][2], vecino[205] = {0};

	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> pts[i][0] >> pts[i][1];

		for(int j = 0; j < i; j++){
			if (pts[j][0] == pts[i][0]){
				if( pts[j][1] > pts[i][1] ){
					vecino[i] |= 1;
					vecino[j] |= 2; 
				}else{
					vecino[i] |= 2;
					vecino[j] |= 1;
				}
			}else if (pts[j][1] == pts[i][1]){
				if(pts[j][0] > pts[i][0]){
					vecino[i] |= 4;
					vecino[j] |= 8; 
				}else{
					vecino[i] |= 8;
					vecino[j] |= 4;
				}
			}
		}

	}

	int count = 0;
	for(int i = 0; i < n; i++)
		if(vecino[i] == 15)
			count++;

	cout << count << endl;

	return 0;
}