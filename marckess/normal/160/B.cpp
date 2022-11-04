
#include <iostream>

using namespace std;

bool comparar(int* mayor, int* menor){
	for (int i = 9, j = 8; i >= 0; i--, j = i - 1 ){
		while ( mayor[i] ){
			if ( j < 0 )
				return 0;
			if ( menor[j] ){
				menor[j]--;
				mayor[i]--;
			}
			else if ( j > 0 )
				j--;
			else
				return false;
		}
	}
	return true;
}

int main(){
	int n, pri[10]={0}, sec[10]={0}, prim = 0, secm = 0;
	char d;

	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> d;
		pri[d - '0']++;
		if(d - '0' > prim)
			prim = d - '0';
	}

	for(int i = 0; i < n; i++){
		cin >> d;
		sec[d - '0']++;
		if(d -'0' > secm)
			secm = d - '0';
	}

	bool f;
	if( prim > secm )
		f = comparar( pri, sec );
	else if ( prim < secm )
		f = comparar( sec, pri );
	else
		f = false;

	if(f)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}