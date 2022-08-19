#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n, m;
	cin >> n >> m;
	int bw = 1;
	for(int i = 0; i < n*m; i++){
		string a;
		cin >> a;
		if(a[0] == 'C' || a[0] == 'M' || a[0] == 'Y'){
			bw = 0;
		}
	}
	if(bw){
		cout << "#Black&White" << endl;
	} else {
		cout << "#Color" << endl;
	}
}