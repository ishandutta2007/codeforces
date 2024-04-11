#include <bits/stdc++.h>
using namespace std;
mt19937 mt(48);

string fr(const string& a){
	return a.substr(0, 2);
}
string bk(const string& a){
	return a.substr(a.size() - 2);
}

string rev(string s){
	reverse(s.begin(), s.end());
	return s;
}

string get(const string& a, size_t k){
	return a.substr(2*k, 2);
}
vector<int> type(string a){
	vector<int> freq(3, 0);
	for(size_t i = 0; i < a.size(); i += 2){
		freq[a[i] - '0' + a[i+1] - '0']++;
	}
	return freq;
}


size_t no = -1;
void solve(){
	int sw = 0;
	vector<size_t> m1, m2;
	string a, b;
	cin >> a >> b;
	size_t lim = a.size() + 1;
	if(type(a) != type(b)){
		cout << -1 << '\n';
		return;
	}
	auto move1 = [&](size_t k){
		if(k == 0) return;
		assert(k * 2 <= a.size());
		m1.push_back(k);
		reverse(a.begin(), a.begin() + 2*k);
	};
	auto move2 = [&](size_t k){
		if(k == 0) return;
		assert(k * 2 <= b.size());
		m2.push_back(k);
		reverse(b.begin(), b.begin() + 2*k);
	};
	int expect = 0;
	while(!a.empty()){
		size_t n = (int)a.size() / 2;
		if(bk(a) == bk(b)){
			expect = 0;
			a.pop_back();
			a.pop_back();
			b.pop_back();
			b.pop_back();
			continue;
		} else {
			assert(!expect);
		}
		expect = 1;
		if(bk(a) == rev(bk(a)) || bk(b) == rev(bk(b))){
			if(bk(b) == rev(bk(b))){
				swap(m1, m2);
				swap(a, b);
				sw ^= 1;
			}
			size_t s = no;
			for(size_t i = 0; i < n; i++){
				if(get(b, i) == bk(a)){
					s = i;
				}
			}
			assert(s != no);
			if(s > 0){
				move2(s+1);
			}
			move2(n);
		} else if(fr(a) != rev(fr(a)) || fr(b) != rev(fr(b))){
			if(fr(b) != rev(fr(b))){
				swap(m1, m2);
				swap(a, b);
				sw ^= 1;
			}
			if(fr(a) == bk(b)){
				move1(1);
			}
			move1(n);
		} else if(fr(a) == fr(b)){
			move1(n);
			move2(n);
		} else {
			size_t found = no;
			for(size_t i = 0; i + 1 < n; i++){
				if(a.substr(0, 4) == rev(b.substr(i*2, 4))){
					found = i;
					break;
				}
			}
			if(found != no){
				move2(found+2);
				move1(n);
				move2(n);
				continue;
			}
			for(size_t i = 0; i + 1 < n; i++){
				if(b.substr(0, 4) == rev(a.substr(i*2, 4))){
					found = i;
					break;
				}
			}
			if(found != no){
				move1(found+2);
				move2(n);
				move1(n);
				continue;
			}
			for(size_t i = 0; i < n; i++){
				if(b.substr(i*2, 2) == bk(a)){
					found = i;
				}
			}
			if(found != no){
				move2(found+1);
				move2(n);
				continue;
			}
			for(size_t i = 0; i < n; i++){
				if(a.substr(i*2, 2) == bk(b)){
					found = i;
				}
			}
			if(found != no){
				move1(found+1);
				move1(n);
				continue;
			}

			for(size_t i = 0; i + 1 < n; i++){
				if(a.substr(0, 4) == b.substr(i*2, 4)){
					found = i;
					break;
				}
			}
			if(found != no){
				move2(found+2);
				move2(2);
				move1(n);
				move2(n);
				continue;
			}
			for(size_t i = 0; i + 1 < n; i++){
				if(b.substr(0, 4) == a.substr(i*2, 4)){
					found = i;
					break;
				}
			}
			if(found != no){
				move1(found+2);
				move1(2);
				move2(n);
				move1(n);
				continue;
			}

			if(a.substr(0, 4) == "0011" || a.substr(0, 4) == "1100"){
				for(size_t i = 0; i < n; i++){
					if(fr(a) == b.substr(i*2, 2)){
						found = i;
						break;
					}
				}
				assert(found != no);
				move2(found);
				move2(found+1);
				move2(n);
				move1(n);
				continue;
			}
			if(b.substr(0, 4) == "0011" || b.substr(0, 4) == "1100"){
				for(size_t i = 0; i < n; i++){
					if(fr(b) == a.substr(i*2, 2)){
						found = i;
						break;
					}
				}
				assert(found != no);
				move1(found);
				move1(found+1);
				move1(n);
				move2(n);
				continue;
			}
			move1(1 + mt() % (n-1));
			expect = 0;
		}
	}
	assert(a.empty() && b.empty());
	if(sw){
		swap(m1, m2);
	}
	reverse(m2.begin(), m2.end());
	m1.insert(m1.end(), m2.begin(), m2.end());
	assert(m1.size() <= lim);
	cout << m1.size() << '\n';
	for(size_t a : m1){
		cout << a * 2 << ' ';
	}
	cout << '\n';
}
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for(int t = 0; t < T; t++){
		solve();
	}
}