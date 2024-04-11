#include <iostream>
using namespace std;

int main(){
	int n; 
	cin >> n;
	int counter = 0 ; 
	int a[n];
	for(int i = 0 ; i < n; i++){
		cin >> a[i]; 
	}
	for(int i = n - 2 ; i >= 0; i--){
		if ( a[i] < a[i+1] )
			counter++;
		else
			break;
	}



	cout << n - 1 -  counter << endl;
}