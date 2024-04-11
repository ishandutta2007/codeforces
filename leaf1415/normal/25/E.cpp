#include <iostream>
#include <string>
#include <algorithm>
#define llint unsigned long long
#define B 107

using namespace std;

string s[3];
llint dist[3][3];
llint bpow[100005];

bool contain(string &s, string &t)
{
	if(s.size() < t.size()) return false;
	llint hash_t = 0;
	for(int i = 0; i < t.size(); i++){
		hash_t += t[i] * bpow[t.size()-1 - i];
	}
	
	llint hash_s = 0;
	for(int i = 0; i < t.size(); i++){
		hash_s += s[i] * bpow[t.size()-1 - i];
	}
	if(hash_s == hash_t) return true;
	for(llint i = t.size(); i < s.size(); i++){
		hash_s = hash_s * B - s[i-t.size()] * bpow[t.size()] + s[i];
		if(hash_s == hash_t) return true;
	}
	return false;
}

llint match(string &s, string &t)
{
	llint n = min(s.size(), t.size());
	
	llint ret = 0;
	llint hash_s = 0, hash_t = 0;
	for(llint i = 1; i <= n; i++){
		hash_t = hash_t * B + t[i-1];
		hash_s += s[s.size()-i] * bpow[i-1];
		if(hash_s == hash_t) ret = max(ret, i);
	}
	return ret;
}

int main(void)
{
	cin >> s[0] >> s[1] >> s[2];
	
	llint val = 1;
	for(int i = 0; i < 100005; i++){
		bpow[i] = val;
		val *= B;
	}
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(i == j) continue;
			if(contain(s[i], s[j])){
				for(int k = 0; k < 3; k++) dist[j][k] = s[j].size();
				break;
			}
		}
	}
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(i == j) continue;
			dist[i][j] = max(dist[i][j], match(s[i], s[j]));
		}
	}
	
	llint ans = 0;
	ans = max(ans, dist[0][1] + dist[1][2]);
	ans = max(ans, dist[0][2] + dist[2][1]);
	ans = max(ans, dist[1][0] + dist[0][2]);
	ans = max(ans, dist[1][2] + dist[2][0]);
	ans = max(ans, dist[2][0] + dist[0][1]);
	ans = max(ans, dist[2][1] + dist[1][0]);
	cout << s[0].size() + s[1].size() + s[2].size() - ans << endl;
	
	return 0;
}