#include <bits/stdc++.h>
using namespace std;
string s;
int N;
vector<int> p0, p1;

map<tuple<int,int>, int> memo_sort_jump;

int sort_jump(tuple<int,int> x){
	if(!memo_sort_jump.count(x)){
		int ans = -1;
		auto [l, n] = x;
		assert(n > 0);
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
						int st = l3;
						int en = N;
						while(st + 1 < en){
							int m = (st + en) / 2;
							if(p0[m] - p0[l3] < n/2 && p1[m] - p1[l3] < (n+1)/2){
								st = m;
							} else {
								en = m;
							}
						}
						ans = en;
					}
				}
			}
		}
		memo_sort_jump[x] = ans;
	}
	return memo_sort_jump[x];
}
vector<int> sequence(tuple<int,int> x, vector<int> numbers){
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
	p1 = {1};
	for(char c : s){
		p0.push_back(p0.back() + (c == '0'));
		p1.push_back(p1.back() + (c == '1'));
	}
	for(int len = 1; ; len++){
		if(sort_jump({0, len}) == N){
			vector<int> numbers(len, 0);
			for(int i = 0; i < len; i++) numbers[i] = i;
			vector<int> ans = sequence({0, len}, numbers);
			cout << len << '\n';
			for(int a : ans) cout << (a+1) << ' ';
			cout << '\n';
			break;
		}
	}
}