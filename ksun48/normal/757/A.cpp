#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	string a;
	cin >> a;
	string b = "Bulbasaur";
	map<char,int> t;
	for(int i = 0; i < a.size(); i++){
		t[a[i]]++;
	}
	int ans = 0;
	while(1){
		for(int i = 0; i < b.size(); i++){
			t[b[i]]--;
			if(t[b[i]] < 0){
				cout << ans << endl;
				return 0;
			}

		}
		ans++;
	}
}