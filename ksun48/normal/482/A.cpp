#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	int k;
	cin >> n >> k;
	int a = 1;
	int b = n;
	int counter = 0;
	for(int i = 0; i < k; i++){
		counter = 1 - counter;
		if(counter == 0){
			cout << a << " ";
			a++;
		} else {
			cout << b << " ";
			b--;
		}
	}
	for(int i = k; i < n; i++){
		if(counter == 0){
			cout << a << " ";
			a++;
		} else {
			cout << b << " ";
			b--;
		}
	}
	cout << endl;


}

// 1 5 2 4 3