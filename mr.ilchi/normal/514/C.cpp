#include <bits/stdc++.h>
using namespace std;

const int base = 701;
const int mod = 1e9 + 7;
const int mod2= 1e9 + 9;

int p[1<<20], p2[1<<20];

int main(){
	p[0] = 1, p2[0] = 1;
	for (int i=1; i<(1<<20); i++){
		p [i] = p [i-1] * (long long)base % mod;
		p2[i] = p2[i-1] * (long long)base % mod2;
	}
	int n,m; cin >> n >> m;
	set< pair<int,int> > SET;
	for (int i=0; i<n; i++){
		string s; cin >> s;
		int x = 0, y = 0;
		for (int j=0; j<(int)s.size(); j++){
			x = (x + (long long)s[j] * p[j]) % mod;
			y = (y + (long long)s[j] * p[j]) % mod2;
		}
		SET.insert(pair<int,int>(x,y));
	}
	for (int o=0; o<m; o++){
		string s; cin >> s;
		int x = 0, y = 0;
		for (int i=0; i<(int)s.size(); i++){
			x = (x + p[i] * (long long)s[i]) % mod;
			y = (y + p[i] * (long long)s[i]) % mod2;
		}
		bool flag = false;
		for (int i=0; i<(int)s.size() && !flag; i++){
			x = (x - (long long)p[i] * s[i]) % mod;
			y = (y - (long long)p[i] * s[i]) % mod2;
			if (x < 0) x+= mod; 
			if (y < 0) y+= mod2;
			for (char ch='a'; ch<='c' && !flag; ch++) if (ch != s[i]){
				x = (x + (long long)p[i] * ch) % mod;
				y = (y + (long long)p[i] * ch) % mod2;
				if (SET.find(pair<int,int>(x,y)) != SET.end())
					flag = true;
				x = (x - (long long)p[i] * ch) % mod; if (x < 0) x+= mod;
				y = (y - (long long)p[i] * ch) % mod2; if (y < 0) y+= mod2;
			}
			x = (x + (long long)p[i] * s[i]) % mod;
			y = (y + (long long)p[i] * s[i]) % mod2;
		}
		cout << (flag ? "YES" : "NO") << endl;
	}
	return 0;
}