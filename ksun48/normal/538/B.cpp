#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	int stuff[7];
	int m = 0;
	for(int i = 0; i < 7; i++){
		stuff[i] = n%10;
		n /= 10;
		m = max(m, stuff[i]);
	}
	cout << m << endl;
	while(1){
		int a = 0;
		for(int i = 6; i >= 0; i--){
			a *= 10;
			if(stuff[i] > 0){
				a++;
				stuff[i]--;
			}

		}
		if(a > 0){
			cout << a << " ";
		} else {
			cout << endl;
			break;
		}

	}

}