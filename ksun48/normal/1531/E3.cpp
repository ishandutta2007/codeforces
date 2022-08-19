#include <bits/stdc++.h>
using namespace std;

string s;
int N;
vector<int> p0, p1;
vector<int> ind0, ind1;

int sort_jump(pair<int,int> x){
	int ans = -1;
	auto [l, n] = x;
	if(l > N) return -1;
	if(n == 1){
		ans = l;
	} else {
		int l2 = sort_jump({l, n/2});
		if(l2 == -1){
			ans = -1;
		} else {
			int l3 = sort_jump({l2, (n+1)/2});
			if(l3 == -1){
				ans = -1;
			} else {
				if(p0[N] - p0[l3] < n/2 && p1[N] - p1[l3] < (n+1)/2){
					ans = -1;
				} else {
					ans = min(ind0[p0[l3] + n/2], ind1[p1[l3] + (n+1)/2]);
				}
			}
		}
	}
	return ans;
}
vector<int> sequence(pair<int,int> x, vector<int> numbers){
	auto [l, n] = x;
	assert(n > 0);
	assert((int)numbers.size() == n);
	if(n == 1){
		return numbers;
	} else {
		int l2 = sort_jump({l, n/2});
		int l3 = sort_jump({l2, (n+1)/2});
		int st = l3;
		int en = N;
		while(st + 1 < en){
			int m = (st + en) / 2;
			if(p0[m] - p0[l3] < n/2 && p1[m] - p1[l3] < (n+1) / 2){
				st = m;
			} else {
				en = m;
			}
		}
		vector<int> a, b;
		int c = 0;
		for(int cur = l3; cur < en; cur++){
			((s[cur] == '0') ? a : b).push_back(numbers[c]);
			c++;
		}
		while((int)a.size() < n/2){
			a.push_back(numbers[c]);
			c++;
		}
		while((int)b.size() < (n+1)/2){
			b.push_back(numbers[c]);
			c++;
		}
		a = sequence({l, n/2}, a);
		b = sequence({l2, (n+1)/2}, b);
		a.insert(a.end(), b.begin(), b.end());
		return a;
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	cin >> s;
	N = (int)s.size();
	p0 = {0};
	p1 = {0};
	for(char c : s){
		p0.push_back(p0.back() + (c == '0'));
		p1.push_back(p1.back() + (c == '1'));
	}
	ind0.push_back(0);
	ind1.push_back(0);
	for(int i = 0; i < N; i++){
		if(s[i] == '0') ind0.push_back(i+1);
		if(s[i] == '1') ind1.push_back(i+1);
	}
	for(int i = 0; i <= N; i++) ind0.push_back(N+1);
	for(int i = 0; i <= N; i++) ind1.push_back(N+1);
	int st = 0;
	int en = 2*N+1;
	while(true){
		int len = (st + en) / 2;
		int x = sort_jump({0, len});
		if(x == N){
			vector<int> numbers(len, 0);
			for(int i = 0; i < len; i++) numbers[i] = i;
			vector<int> ans = sequence({0, len}, numbers);
			cout << len << '\n';
			for(int a : ans) cout << (a+1) << ' ';
			cout << '\n';
			break;
		} else if(x == -1){
			en = len;
		} else {
			st = len;
		}
	}
}