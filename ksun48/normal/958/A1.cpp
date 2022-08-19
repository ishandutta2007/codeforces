#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;
vector<string> g(){
	vector<string> q(n);
	for(int i = 0; i < n; i++){
		cin >> q[i];
	}
	return q;
}
vector<string> rot(vector<string> q){
	vector<string> a = q;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			a[i][j] = q[n-1-j][i];	
		}
	}
	return a;
}
int main(){
	cin >> n;
	vector<string> a = g();
	vector<string> b = g();
	int ok1 = (a == b || a == rot(b) || a == rot(rot(b)) || a == rot(rot(rot(b))));
	reverse(b.begin(), b.end());
	int ok2 = (a == b || a == rot(b) || a == rot(rot(b)) || a == rot(rot(rot(b))));
	if(ok1 || ok2){
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}