#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#define llint long long

using namespace std;

struct BIT{
	int size;
	vector<int> bit;
	BIT(){size = 0;}
	BIT(int s){
		size = s;
		bit.resize(size+1);
		init();
	}
	void init(){
		for(int i = 1; i <= size; i++) bit[i] = 0;
	}
	int query(int i){
		int ret = 0;
		while(i > 0){
			ret += bit[i];
			i -= i&(-i);
		}
		return ret;
	}
	void add(int i, int x){
		while(i <= size){
			bit[i] += x;
			i += i&(-i);
		}
	}
};

llint Q;
string s;
BIT bit[26];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	cin >> Q;
	int n = s.size();
	s = "#" + s;
	
	for(int i = 0; i < 26; i++) bit[i] = BIT(100000);
	for(int i = 1; i <= n; i++) bit[s[i]-'a'].add(i, 1);
	
	llint t;
	for(int q = 0; q < Q; q++){
		cin >> t;
		if(t == 1){
			llint p; char c;
			cin >> p >> c;
			bit[s[p]-'a'].add(p, -1);
			s[p] = c;
			bit[s[p]-'a'].add(p, 1);
		}
		else{
			llint l, r, ans = 0;
			cin >> l >> r;
			for(int i = 0; i < 26; i++){
				if(bit[i].query(r) - bit[i].query(l-1)) ans++;
			}
			cout << ans << "\n";
		}
	}
	flush(cout);
	
	return 0;
}