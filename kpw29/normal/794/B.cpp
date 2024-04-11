#include "bits/stdc++.h"
using namespace std;
int n , h;
int main(){
	cin >> n >> h;
	for(int i = 1 ; i < n ; ++i){
		printf("%.9lf " , h * sqrt(1.0 * i / n));
	}
}