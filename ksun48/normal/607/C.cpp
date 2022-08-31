#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	n = a.size();
	int pa = 0;
	int pb = n;
	int ma[n];
	int mb[n];
	for(int i = 0; i < n; i++){
		if(a[i] == 'N'){
			ma[i] = 1;
		} else if(a[i] == 'S'){
			ma[i] = -1;
		}
		if(a[i] == 'W'){
			ma[i] = 2;
		} else if(a[i] == 'E'){
			ma[i] = -2;
		}

		if(b[i] == 'N'){
			mb[i] = 1;
		} else if(b[i] == 'S'){
			mb[i] = -1;
		}
		if(b[i] == 'W'){
			mb[i] = 2;
		} else if(b[i] == 'E'){
			mb[i] = -2;
		}
	}
	vector<int> stuff;
	for(int i = n-1; i >= 0; i--){
		stuff.push_back(-mb[i]);
	}
	for(int i = 0; i < n; i++){
		stuff.push_back(ma[i]);
	}
	stuff.push_back(3);
	int t[2*n+2];
	t[0] = -1;
	t[1] = 0;
	int i = 2;
	int c = 0;
	while(i <= 2*n){
		if(stuff[i-1] == stuff[c]){
			t[i] = c+1;
			c++;
			i++;
		} else if(c > 0){
			c = t[c];
		} else {
			t[i] = 0;
			i++;
		}
	}
	for(int i = 0; i <= 2*n; i++){
		//cout << stuff[i] << " " << t[i] << endl;
	}
	if(t[2*n] > 0){
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
	}

}