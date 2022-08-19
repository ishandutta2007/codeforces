#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
set<string> a;
string c[210000];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> c[i];
	}
	for(int i = n-1; i >= 0; i--){
		if(a.find(c[i]) == a.end()) cout << c[i] << endl;
		a.insert(c[i]);
	}
}