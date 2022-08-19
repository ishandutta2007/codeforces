#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	using ll = long long;
	ll T;
	cin >> n >> T;
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	if(!s.empty()){
		T -= (1ll << (s.front() - 'a'));
		s = s.substr(1);
	}
	if(!s.empty()){
		T += (1ll << (s.front() - 'a'));
		s = s.substr(1);
	}
	vector<ll> freq(27, 0);
	for(char x : s){
		freq[x-'a']++;
		T += (1ll << (x-'a'));
	}
	if(T % 2 == 1 || T < 0){
		cout << "No" << '\n';
		exit(0);
	}
	T /= 2;
	ll knap = 0;
	for(int i = 0; i < 27; i++){
		knap += freq[i];
		if(T & 1){
			if(knap == 0){
				cout << "No" << '\n';
				exit(0);
			} else {
				knap--;
				T--;
			}
		}
		T /= 2;
		knap /= 2;
	}
	if(T >= 0 && T <= knap){
		cout << "Yes" << '\n';
	} else {
		cout << "No" << '\n';
	}
}