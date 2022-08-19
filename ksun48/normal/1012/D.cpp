#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int score(string s){
	int num1 = 1;
	for(int i = 0; i + 1 < s.size(); i++){
		num1 += (s[i] != s[i+1]);
	}
	return num1;
}

vector<pair<int,int> > solve(string s, string t, int q){
	s = "a" + s;
	s += ('a' + q);
	t = "b" + t;
	t += ('a' + (1-q));
	//cout << s << " " << t << endl;
	vector<pair<int,int> > ans;
	int num1 = score(s);
	int num2 = score(t);
	if(num1 == 1 && num2 == 1){
		return ans;
	}
	vector<int> g1;
	vector<int> g2;
	for(int i = 0; i < s.size(); i++){
		if(i == 0 || s[i] != s[i-1]){
			g1.push_back(1);
		} else {
			g1[g1.size()-1]++;
		}
	}
	g1[0]--;
	g1[g1.size()-1]--;
	for(int i = 0; i < t.size(); i++){
		if(i == 0 || t[i] != t[i-1]){
			g2.push_back(1);
		} else {
			g2[g2.size()-1]++;
		}
	}
	g2[0]--;
	g2[g2.size()-1]--;

	if(g1.size() == 1){
		g1.push_back(0);
		g1.push_back(0);
	} else if(g2.size() == 1){
		g2.push_back(0);
		g2.push_back(0);
	}
	if((g1.size() - g2.size()) % 4 != 0){
		g1.push_back(0);
		g1.push_back(0);
	}
	// do stuff now;
	//cout << s << " " << t << endl;
	//cout << g1.size() << " " << g2.size() << endl;
	if(g1.size() != g2.size()){
		int a1 = (g1.size() + 1) / 2;
		int a2 = (g2.size() + 1) / 2;
		vector<int> newg1;
		vector<int> newg2;
		int sum1 = 0;
		int sum2 = 0;
		for(int j = 0; j < a1; j++){
			sum1 += g1[j];
			newg1.push_back(g1[j]);
		}
		for(int j = 0; j < a2; j++){
			sum2 += g2[j];
			newg2.push_back(g2[j]);
		}
		ans.push_back({sum1, sum2});
		for(int j = a1; j < g1.size(); j++){
			if(j == a1){
				newg2[newg2.size() - 1] += g1[j];
			} else {
				newg2.push_back(g1[j]);
			}
		}
		for(int j = a2; j < g2.size(); j++){
			if(j == a2){
				newg1[newg1.size() - 1] += g2[j];
			} else {
				newg1.push_back(g2[j]);
			}
		}
		g1 = newg1;
		g2 = newg2;
	}
	assert(g1.size() == g2.size());
	int psum1 = 0;
	int psum2 = 0;
	for(int z = 1; z < g1.size(); z++){
		psum1 += g1[z-1];
		psum2 += g2[z-1];
	}
	for(int z = (int)g1.size() - 1; z >= 1; z--){
		ans.push_back({psum1, psum2});
		psum1 -= g1[z-1];
		psum2 -= g2[z-1];
	}

	for(int i = 0; i < ans.size(); i++){
		if(i % 2){
			swap(ans[i].first, ans[i].second);
		}
	}
}


int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	string s;
	string t;
	cin >> s >> t;
	vector<pair<int,int> > c(700000, {-1, -1});
	for(int r = 0; r < 2; r++){
		for(int z = 0; z < 2; z++){
			vector<pair<int,int> > ans = solve(s, t, z);
			if(r == 1){
				for(int i = 0; i < ans.size(); i++){
					swap(ans[i].first, ans[i].second);
				}
			}
			if(ans.size() <= c.size()){
				c = ans;
			}
		}
		swap(s,t);
	}
	cout << c.size() << '\n';
	for(int i = 0; i < c.size(); i++){
		cout << c[i].first << " " << c[i].second << '\n';
	}
	return 0;
}