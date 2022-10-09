#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define trav(x,v) for(auto &x : v)
#define all(v) v.begin(),v.end()
#define sz(v) (int)(v.size())
#define rrep(i,a,b) for(int i = b; i --> a;)
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

bool digit(char c){
	return '0' <= c && c <= '9';
}

bool alphanum(char c){
	return digit(c) || ('a' <= c && c <= 'z') || c=='_' || c=='$' || ('A' <= c && c <= 'Z');
}

set<string> reserve;

int nx(string &s, int cur){
	assert(cur >= 0 && cur < sz(s));

	if(digit(s[cur])){
		int j = cur+1;
		while(j < sz(s) && digit(s[j])) ++j;
		rrep(jj,j,sz(s)+1) if(reserve.count(s.substr(cur, jj-cur))) return jj;
		return j;
	} else if(alphanum(s[cur])){
		int j = cur+1;
		while(j < sz(s) && alphanum(s[j])) ++j;
		rrep(jj,j,sz(s)+1) if(reserve.count(s.substr(cur, jj-cur))) return jj;
		return j;
	} else {
		rrep(jj,cur+1,sz(s)+1) if(reserve.count(s.substr(cur,jj-cur))) return jj;
		assert(false);
	}
}

bool isword(string t){
	return !reserve.count(t) && !isdigit(t[0]);
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n, m;
	cin >> n;
	rep(_,0,n){
		string s;
		cin >> s;
		reserve.insert(s);
	}
	vector<string> target;
	rep(a,0,26){
		string s = {char('a' + a)};
		if(!reserve.count(s)) target.push_back(s);
	}
	rep(a,0,26) rep(b,0,26){
		string s = {char('a' + a), char('a' + b)};
		if(!reserve.count(s)) target.push_back(s);
	}
	rep(a,0,26) rep(b,0,26) rep(c,0,26){
		string s = {char('a' + a), char('a' + b), char('a' + c)};
		if(!reserve.count(s)) target.push_back(s);
	}
	vector<string> toks;
	map<string, string> ren;
	int ix = 0;
	cin >> m;
	rep(_,0,m+1){
		string ll;
		getline(cin,ll);
		rep(i,0,sz(ll)) if(ll[i] == '#'){
			ll = ll.substr(0,i);
			break;
		}
		stringstream ss(ll);
		while(ss){
			string s;
			ss >> s;
			int cur = 0;
			while(cur < sz(s)){
				int xx = nx(s,cur);
				string t = s.substr(cur, xx-cur);
				if(isword(t)){
					if(!ren.count(t)){
						ren[t] = target[ix++];
					}
					toks.push_back(ren[t]);
				} else {
					toks.push_back(t);
				}
				cur = xx;
			}
		}
	}
	int k = sz(toks);

	vector<bool> sp(k, false);
	int to = k;
	rrep(i,0,k){
		string s = "";
		rep(j,i,to) s += toks[j];
		if(nx(s,0) == sz(toks[i])){
			;
		} else {
			sp[i] = true;
			to = i+1;
		}
	}
	rep(i,0,k){
		cout << toks[i];
		if(sp[i]) cout << ' ';
	}
	cout << endl;
}