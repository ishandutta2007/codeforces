#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int t, n;
	char a[1000], b[1000];
	cin >> t;
	while(t--){
		cin >> n;
		int R = 0, B = 0;
		for(int i = 0; i < n; i++){
			cin >> a[i];

		}
		for(int i = 0; i < n; i++){
			cin >> b[i];
			if(a[i] > b[i])R++;
			if(a[i] < b[i])B++;
		}
		if(R>B)cout << "RED\n";
		if(R<B)cout << "BLUE\n";
		if(R==B)cout << "EQUAL\n";
	}



	return 0;
}