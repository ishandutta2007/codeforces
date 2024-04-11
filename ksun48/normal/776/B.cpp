#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main() {
	int n;
	scanf("%d", &n);
	vector<int> p;
	if(n == 1){
		cout << 1 << endl << 1 << endl;
		return 0;
	} else if(n == 2){
		cout << 1 << endl << 1 << " " << 1 << endl;
		return 0;
	}
	cout << 2 << endl;
	for(int i = 2; i <= n+1; i++){
		int ok = 1;
		for(int j = 0; j < p.size(); j++){
			if(i % p[j] == 0){
				ok =0;
				break;
			}
			if(p[j] * p[j] >= i){
				break;
			}
		}
		if(ok){
			printf("2 ");
			p.push_back(i);
		} else {
			printf("1 ");
		}
	}
}