#include <bits/stdc++.h>
#define fore(i, a, b) for(int i = a; i < b; ++i)
using namespace std;
 
const int MAXN = 1010;

//c[i][j] = number of cards player i has, with the number j
int c[MAXN][MAXN];
 
//extras[i] is the stack of repeated cards for player i.
vector<int> extras[MAXN];
 
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	fore(i, 0, n){
		fore(j, 0, n){
			int x; cin >> x; x--;
			c[i][x]++;
			if(c[i][x] > 1) extras[i].push_back(x);
		}
	}
	vector<vector<int>> res;
	//First part
	while(true){
		//oper will describe the next operation to perform
		vector<int> oper(n);
		//s will be the first non-diverse player
		int s = -1;
		fore(i, 0, n){
			if(extras[i].size()){
				s = i;
				break;
			}
		}
		if(s == -1) break;
		//last_card will be the card that the previous player passed
		int last_card = -1;
		fore(i, s, s + n){
			int real_i = i % n;
			if(extras[real_i].size()){
				last_card = extras[real_i].back();
				extras[real_i].pop_back();
			}
			oper[real_i] = last_card;
		}
		res.push_back(oper);
		fore(i, 0, n){
			int i_next = (i + 1) % n;
			c[i][oper[i]]--;
			c[i_next][oper[i]]++;
		}
		fore(i, 0, n){
			int i_next = (i + 1) % n;
			if(c[i_next][oper[i]] > 1) extras[i_next].push_back(oper[i]);
		}
	}
	//Second part
	fore(j, 1, n){
		vector<int> oper;
		fore(i, 0, n) oper.push_back((i - j + n) % n);
		fore(i, 0, j) res.push_back(oper);
	}
	cout << res.size() << "\n";
	for(auto i : res){
		for(auto j : i) cout<< j + 1 << " ";
		cout << "\n";
	}
	return 0;
}