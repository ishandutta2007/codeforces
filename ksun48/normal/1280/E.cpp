#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct node {
	char type;
	vector<node*> children;
	ll dp = 0;
	ll r = 0;
};

node* get(string& s, int& idx){
	node* v = new node();
	if(s[idx] == '*'){
		v->type = '*';
		idx++;
		return v;
	} else if(s[idx] == '('){
		idx++;
		while(true){
			v->children.push_back(get(s, idx));
			if(s[idx] == 'P' || s[idx] == 'S'){
				v->type = s[idx];
				idx++;
			} else if(s[idx] == ')'){
				idx++;
				break;
			} else assert(false);
		}
	} else assert(false);
	return v;
}

const ll Z = 2e18;

ll sq(ll r){
	if(r > Z / r) return Z;
	return min(r * r, Z);
}

void make_dp(node* v){
	if(v->type == '*'){
		v->dp = 1;
	} else {
		for(node* w : v->children){
			make_dp(w);
		}
		if(v->type == 'S'){
			v->dp = Z;
			for(node* w : v->children) v->dp = min(v->dp, w->dp);
		} else if(v->type == 'P'){
			v->dp = 0;
			for(node* w : v->children) v->dp += w->dp;
		} else assert(false);
	}
}


ll res = 0;
void make_resistances(node* v, bool good){
	if(v->type == '*'){
		cout << " " << (good ? res : 0);
	} else if(v->type == 'P'){
		for(node* w : v->children){
			make_resistances(w, good);
		}
	} else if(v->type == 'S'){
		for(node* w : v->children){
			if(w->dp == v->dp){
				make_resistances(w, good);
				good = false;
			} else {
				make_resistances(w, false);
			}
		}
	} else assert(false);
}

void solve(){
	string s;
	getline(cin, s);
	auto g = s.find(' ');
	ll R = stoll(s.substr(0, g));

	s = s.substr(g+1);

	s.resize(remove_if(s.begin(), s.end(), [&](char a){ return a == ' '; } ) - s.begin());
	int idx = 0;
	node* z = get(s, idx);
	make_dp(z);
	res = R * z->dp;
	cout << "REVOLTING";
	make_resistances(z, true);
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	string s;
	getline(cin, s);
	T = stoi(s);
	while(T--) solve();
}