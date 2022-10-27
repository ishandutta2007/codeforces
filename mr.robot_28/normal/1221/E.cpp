#include <bits/stdc++.h>

using namespace std;

const int N = int(2e5) + 99;

int t;
int a, b;
string s;

int main() {
	cin >> t;
	for(int tc = 0; tc < t; ++tc){
		cin >> a >> b >> s;
		vector <int> v;
		int l = 0;
		while(l < s.size()){
			if(s[l] == 'X'){
				++l;
				continue;
			}

			int r = l + 1;
			while(r < s.size() && s[r] == '.') ++r;
			v.push_back(r - l);
			l = r;
		}
		
		bool ok = true;
		int id = -1;
		int cnt = 0;
		for(int i = 0; i < v.size(); ++i){
			if(b <= v[i] && v[i] < a) ok = false;
			if(b + b <= v[i]){
				if(id == -1) id = i;
				else ok = false;
			}
			if(a <= v[i] && v[i] < b + b) ++cnt; 
		}

		if(!ok){
			cout << "NO" << endl;			
			continue;
		}

		if(id == -1){
			if(cnt & 1) cout << "YES" << endl;
			else cout << "NO" << endl;
			continue;
		}

		ok = false;
		int sz = v[id];
		assert(sz >= a);
		for(int rem1 = 0; sz - a - rem1 >= 0; ++rem1){
			int rem2 = sz - a - rem1;
			int ncnt = cnt;
			if((rem1 >= b + b) || (b <= rem1 && rem1 < a)) continue;
			if((rem2 >= b + b) || (b <= rem2 && rem2 < a)) continue;

			if(rem1 >= a) ++ncnt;
			if(rem2 >= a) ++ncnt;
			if(ncnt % 2 == 0) ok = true;
		}
		
		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}