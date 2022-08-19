#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h> /** keep-include */
using namespace __gnu_pbds;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

int my_solve(string s){
	int n = (int)s.size();
	Tree<int> pos;
	for(int i = 0; i < n; i++) pos.insert(i);
	pos.insert(-1);
	pos.insert(n);

	map<char, int> freq;

	set<int> where;
	map<char, set<int> > char_where;
	for(int i = 0; i + 1 < n; i++){
		if(s[i] == s[i+1]){
			where.insert(i);
			char_where[s[i]].insert(i);
			freq[s[i]]++;
		}
	}
	vector<pair<int,int> > stuff;
	auto kill = [&](int f, int g){
		int a = (int)pos.order_of_key(f);
		int b = (int)pos.order_of_key(g+1) - 1;
		stuff.push_back({a, b});
		while(true){
			int p = *pos.lower_bound(f);
			if(p > g) break;
			pos.erase(p);
		}
	};
	while(pos.size() > 2){
		if(where.empty()){
			kill(0, n-1);
			break;
		}
		char best = 'a';
		int freq_pos = 0;
		for(char i = 'a'; i <= 'z'; i++){
			if(freq[i] > 0) freq_pos++;
			if(freq[i] > freq[best]) best = i;
		}
		if(freq_pos == 1){
			int g = *where.begin();
			char_where[s[g]].erase(g);
			freq[s[g]]--;
			where.erase(g);
			kill(0, g);
			continue;
		}
		for(char c = 'a'; c <= 'z'; c++){
			if(char_where[c].empty()) continue;
			int x = *char_where[c].begin();
			if(x != *where.begin()){
				int g = *prev(where.find(x)) + 1;
				if(s[g] != best && s[x] != best) continue;
				kill(g, x);
				where.erase(g-1);
				where.erase(x);
				char_where[s[g-1]].erase(g-1);
				char_where[s[x]].erase(x);
				freq[s[g]]--;
				freq[s[x]]--;
				break;
			}
		}
	}
	cout << stuff.size() << '\n';
	for(pair<int,int> p : stuff){
		cout << p.first << ' ' << p.second << '\n';
	}
	return (int)stuff.size();
}

void solve(){
	string s;
	cin >> s;
	my_solve(s);
}

int main(){
	int T;
	cin >> T;
	while(T--) solve();
}