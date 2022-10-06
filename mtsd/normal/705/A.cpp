#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin >>n;
	for(int i=0;i<n-1;i++){
		if(i%2){
			cout << "I love that ";
		}else{
			cout << "I hate that ";
		}
	}
	if(n%2){
		cout << "I hate it"<<endl;
	}else{
		cout << "I love it"<<endl;
	}
	return 0;
}