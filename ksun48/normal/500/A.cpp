#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n, m;
	cin >> n >> m;
	int stuff[n];
	int yes[n];
	for(int i = 0; i < n-1; i++){
		cin >> stuff[i];
		yes[i] = 0;
	}
	yes[0] = 1;
	for(int i = 0; i < n-1; i++){
		if(yes[i]){
			yes[i+stuff[i]] = 1;
		}
	}
	if(yes[m-1] ==1){
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

}