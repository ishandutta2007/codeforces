#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	string color = "blue";
	bool locked = false;
	while(n--){
		string s;
		cin >> s;
		if(s == "lock"){
			locked = true;
		} else if(s == "unlock"){
			locked = false;
		} else if(!locked){
			color = s;
		}
	}
	cout << color << '\n';
}