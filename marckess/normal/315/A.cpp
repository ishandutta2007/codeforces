#include <iostream>

using namespace std;

int main(){
	int n, bot[105][2], brand[1005] = {0};

	cin >> n;

	for(int i = 0; i < n; i++ ){
		cin >> bot[i][0] >> bot[i][1];
		brand[bot[i][1]] ++;
	}

	int count = 0;

	for(int i = 0; i < n; i++){
		int aux = brand[bot[i][0]];
		if ( bot[i][0] == bot[i][1] )
			aux--;
		if ( aux <= 0 )
			count ++;
	}

	cout << count;

	return 0;
}