#include<bits/stdc++.h>
using namespace std;
string a[55],s[55];int n;
void trans(string s,string&x){
	x="";
	int m = s.length();
	for(int i=0; i<m; i++){
		if(x=="" || s < x){
			x = s;
		}
		s = s.substr(1,m-1) + s[0];
	}
}
int to(string A,string B){
	int step=0;
	int m = A.length();
	while(A!=B){
		A = A.substr(1,m-1) + A[0];
		step++;
	}
	return step;
}
int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> s[i];
		trans(s[i],a[i]);
	}
	for(int i=1; i<n; i++)
		if(a[i] != a[0]){
			cout << "-1" << endl;
			return 0;
		}
	int bes = 9999;
	int m = a[0].length();
	string A = a[0];
	for(int k=0; k<m; k++){
		int now = 0;
		for(int i=0; i<n; i++){
			now += to(s[i], A);
		}
		bes = min(bes,now);
		A = A.substr(1,m-1) + A[0];
	}
	cout << bes << endl;
	return 0;
}