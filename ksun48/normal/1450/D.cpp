#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	multiset<int> z;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int x : a) z.insert(x);
	{
		vector<int> b = a;
		sort(b.begin(), b.end());
		bool perm = true;
		for(int i = 0; i < n; i++){
			if(b[i] != i+1) perm = false;
		}
		if(perm){
			cout << '1';
		} else {
			cout << '0';
		}
	}
	string s;
	int st = 0;
	int en = n-1;
	for(int i = 1; i < n; i++){
		if(*z.begin() == i){
			s += '1';
		} else {
			s += '0';
		}
		if(a[st] == i){
			st++;
		} else if(a[en] == i){
			en--;
		} else {
			break;
		}
		z.erase(z.find(i));
	}
	s.resize(n-1, '0');
	reverse(s.begin(), s.end());
	cout << s << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}