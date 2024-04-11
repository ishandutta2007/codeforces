#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

struct Trie
{
	struct TrieNode{
		int cnt;
		int next[26];
		TrieNode(){
			cnt = 0;
			for(int i = 0; i < 26; i++) next[i] = -1;
		}
	};
	vector<TrieNode> vec;
	Trie(){
		init();
	}
	init(){
		vec.clear();
		vec.push_back(TrieNode());
	}
	void insert(string &s)
	{
		int p = 0;
		for(int i = 0; i < s.size(); i++){
			int c = s[i]-'a';
			if(vec[p].next[c] == -1){
				vec.push_back(TrieNode());
				vec[p].next[c] = (int)vec.size()-1;
			}
			p = vec[p].next[c];
		}
		vec[p].cnt++;
	}
	void erase(string &s)
	{
		int p = 0;
		for(int i = 0; i < s.size(); i++){
			int c = s[i]-'a';
			if(vec[p].next[c] == -1) return;
			p = vec[p].next[c];
		}
		if(vec[p].cnt > 0) vec[p].cnt--;
	}
	int count(string &s)
	{
		int p = 0;
		for(int i = 0; i < s.size(); i++){
			int c = s[i]-'a';
  			if(vec[p].next[c] == -1) return 0;
			p = vec[p].next[c];
		}
		return vec[p].cnt;
	}
};


llint n;
vector<string> vec[105];
Trie trie;
string str[105];

void get(llint cnt[], string &s)
{
	for(int i = 0; i < 26; i++) cnt[i] = 0;
	for(int i = 0; i < s.size(); i++) cnt[s[i]-'a']++;
}

string S;
void dfs(int v, vector<string> &vec)
{
	for(int i = 0; i < trie.vec[v].cnt; i++) vec.push_back(S);
	for(int i = 0; i < 26; i++){
		if(trie.vec[v].next[i] != -1){
			S += (char)(i+'a');
			dfs(trie.vec[v].next[i], vec);
			S.erase(S.end()-1);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	getline(cin, s);
	n = atoi(s.c_str());
	
	cout << "? " << 1 << " " << n << endl;
	
	for(int i = 0; i < n*(n+1)/2; i++){
		cin >> s;
		//cout << s << endl;
		//getline(cin, s);
		//cout << s << endl;
		if(s.size() == 0) continue;
		sort(s.begin(), s.end());
		vec[(int)s.size()].push_back(s);
		trie.insert(s);
	}
	
	if(n == 1){
		cout << "! " << vec[1][0] << endl;
		return 0;
	}
	
	cout << "? " << 1 << " " << n-1 << endl;
	
	for(int i = 0; i < n*(n-1)/2; i++){
		cin >> s;
		//getline(cin, s);
		//cout << s << endl;
		if(s.size() == 0) continue;
		sort(s.begin(), s.end());
		trie.erase(s);
	}
	
	vector<string> tmp;
	dfs(0, tmp);
	
	for(int i = 0; i < tmp.size(); i++){
		str[tmp[i].size()] = tmp[i];
	}
	
	//for(int i = 0; i < tmp.size(); i++) cout << tmp[i] << " "; cout << endl;
	
	
	string ans;
	ans += str[1];
	
	//for(int i = 1; i <= n; i++) cout << str[i] << " "; cout << endl;
	
	llint a[26], b[26];
	for(int i = 1; i < n; i++){
		get(a, str[i]), get(b, str[i+1]);
		for(int j = 0; j < 26; j++){
			if(a[j] != b[j]){
				ans += (char)(j+'a');
				break;
			}
		}
	}
	reverse(ans.begin(), ans.end());
	cout << "! " << ans << endl;
	
	return 0;
}