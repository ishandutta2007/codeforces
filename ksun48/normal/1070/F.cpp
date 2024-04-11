#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> stuff[12];
	for(int i = 0; i < n; i++){
		int r;
		int b;
		cin >> r >> b;
		stuff[r].push_back(b);
	}
	for(int i = 0; i < 12; i++){
		sort(stuff[i].begin(), stuff[i].end());
		reverse(stuff[i].begin(), stuff[i].end());
	}
	if(stuff[1].size() > stuff[10].size()) swap(stuff[1], stuff[10]);
	
	int ans = 0;
	int na = 0;
	int nb = 0;
	int tot = 0;
	for(int x : stuff[11]){
		tot++;
		na++;
		nb++;
		ans += x;
	}
	for(int x : stuff[1]){
		tot++;
		na++;
		ans += x;
	}
	vector<int> extra;
	for(int x : stuff[10]){
		if(nb >= na){
			extra.push_back(x);
		} else {
			tot++;
			ans += x;
			nb++;
		}
	}
	for(int x : stuff[0]){
		extra.push_back(x);
	}
	sort(extra.begin(), extra.end());
	reverse(extra.begin(), extra.end());
	for(int x : extra){
		if(na * 2 >= (tot + 1)){
			ans += x;
			tot++;
		}
	}
	cout << ans << endl;
}