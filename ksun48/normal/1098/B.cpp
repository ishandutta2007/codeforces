#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


vector<string> s;
string z = "ACGT";

vector<string> ans;
int cost = 1e8;

void test(vector<string> t){
	int cc = 0;
	for(int i = 0; i < s.size(); i++){
		for(int j = 0; j < s[0].size(); j++){
			if(s[i][j] != t[i][j]){
				cc++;
			}
		}
	}
	if(cc < cost){
		cost = cc;
		ans = t;
	}
}

int diff(string a, string b){
	assert(a.size() == b.size());
	int x = 0;
	for(int i = 0; i < a.size(); i++){
		x += a[i] != b[i];
	}
	return x;
}

vector<string> transpose(vector<string> b){
	vector<string> a(b[0].size(), string(b.size(), ' '));
	for(int i = 0; i < a.size(); i++){
		for(int j = 0; j < a[0].size(); j++){
			a[i][j] = b[j][i];
		}
	}
	return a;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	s.resize(n);
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	for(int j = 0; j < 2; j++){
		vector<string> p1 = {"AC", "AG", "AT", "CG", "CT", "GT"};
		vector<string> p2 = {"GT", "CT", "CG", "AT", "AG", "AC"};
		for(int z = 0; z < 6; z++){
			vector<string> stuff = s;
			for(int i = 0; i < s.size(); i++){
				string bank;
				if(i % 2 == 0) bank = p1[z];
				if(i % 2 == 1) bank = p2[z];
				string t1(s[0].size(), ' ');
				string t2(s[0].size(), ' ');
				for(int j = 0; j < s[0].size(); j++){
					t1[j] = bank[j%2];
					t2[j] = bank[1 - j % 2];
				}
				if(diff(t1, s[i]) > diff(t2, s[i])){
					swap(t1, t2);
				}
				stuff[i] = t1;
			}
			test(stuff);
		}
		s = transpose(s);
		ans = transpose(ans);
	}
	for(string x : ans){
		cout << x << '\n';
	}
}