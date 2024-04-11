#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	int a[n];
	int odd = 0;
	int even = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		if(a[i] % 2 == 1){
			odd++;
		} else {
			even++;
		}
	}
	if(n == k){
		if(odd % 2){
			cout << "Stannis" << endl;
		} else {
			cout << "Daenerys" << endl;
		}
		return 0;
	}
	int c = n-k;
	if(c % 2 == 1){
		//S goes first + last
		int t = (c-1)/2;
		if(t >= odd){
			cout << "Daenerys" << endl;
		} else if(t >= even && ((k % 2 == 0)) ){
			cout << "Daenerys" << endl;
		} else {
			cout << "Stannis" << endl;
		}
	} else {
		//S first D last
		int t = c/2;
		if(t >= even && ((k%2) == 1)){
			cout << "Stannis" << endl;
		} else {
			cout << "Daenerys" << endl;
		}
	}


}