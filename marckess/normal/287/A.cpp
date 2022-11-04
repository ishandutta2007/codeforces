
#include <iostream>

using namespace std;

bool isPossible (int m[][5]){
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++ )
			if( m[i][j] + m[i][j+1] + m[i+1][j] + m[i+1][j+1] != 2 )
				return true;
	return false;
}

int main(){
	int test[5][5];
	char x;

	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++){
			cin >> x;
			if(x == '.')
				test[i][j] = 0;
			else
				test[i][j] = 1;
		}

	if(isPossible(test))
		cout << "YES";
	else
		cout << "NO";

	return 0;
}