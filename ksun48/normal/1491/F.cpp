#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	auto query = [&](vector<int> a, vector<int> b){
		cout << "? " << a.size() << " " << b.size() << '\n';
		for(int x : a){
			cout << (x+1) << ' ';
		}
		cout << '\n';
		for(int x : b){
			cout << (x+1) << ' ';
		}
		cout << '\n';
		cout << flush;
		int res;
		cin >> res;
		return res;
	};
	auto answer = [&](vector<int> a){
		cout << "! ";
		cout << a.size() << '\n';
		for(int x : a){
			cout << (x+1) << ' ';
		}
		cout << '\n';
		cout << flush;
	};
	int found = -1;
	for(int i = 1; i < n; i++){
		vector<int> r(i);
		for(int j = 0; j < i; j++) r[j] = j;
		int res = query(r, {i});
		if(res){
			found = i;
			break;
		}
	}
	vector<int> no;
	for(int j = found+1; j < n; j++){
		if(!query({found}, {j})) no.push_back(j);
	}
	int s = 0;
	int e = found-1;
	while(s < e){
		int m = (s+e)/2;
		vector<int> what = {};
		for(int j = s; j <= m; j++){
			what.push_back(j);
		}
		if(query(what, {found})){
			e = m;
		} else {
			s = m+1;
		}
	}
	for(int j = 0; j < found; j++){
		if(j != s) no.push_back(j);
	}
	sort(no.begin(), no.end());
	answer(no);
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}