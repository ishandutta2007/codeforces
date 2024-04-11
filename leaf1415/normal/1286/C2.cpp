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

struct Trie{
	struct TrieNode{
		int num, next[26];
		TrieNode(){
			num = 0;
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
	int seek(string &s)
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
		return p;
	}
	void insert(string &s, int x = 1)
	{
		int p = seek(s);
		vec[p].num += x;
	}
	void erase(string &s, int x = 1)
	{
		int p = seek(s);
		vec[p].num = max(0, vec[p].num - x);
	}
	int count(string &s)
	{
		int p = seek(s);
		return vec[p].num;
	}
};


llint n;
Trie trie;
string str[105];
llint cnt[105][26], dif[105][26];

void get(llint cnt[], string &s)
{
	for(int i = 0; i < 26; i++) cnt[i] = 0;
	for(int i = 0; i < s.size(); i++) cnt[s[i]-'a']++;
}
void getdif(llint a[], llint b[], llint c[])
{
	for(int i = 0; i < 26; i++) c[i] = a[i] - b[i];
}

string S;
void dfs(int v, vector<string> &vec)
{
	for(int i = 0; i < trie.vec[v].num; i++) vec.push_back(S);
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
	
	cin >> n;
	
	string s;
	if(n == 1){
		cout << "? 1 1" << endl;
		cin >> s;
		cout << "! " << s << endl;
		return 0;
	}
	llint m = n/2;
	
	cout << "? " << 1 << " " << m << endl;
	for(int i = 0; i < m*(m+1)/2; i++){
		cin >> s;
		sort(s.begin(), s.end());
		trie.insert(s);
	}
	if(m >= 2){
		cout << "? " << 1 << " " << m-1 << endl;
		for(int i = 0; i < m*(m-1)/2; i++){
			cin >> s;
			sort(s.begin(), s.end());
			trie.erase(s);
		}
	}
	
	vector<string> tmp;
	dfs(0, tmp);
	for(int i = 0; i < tmp.size(); i++) str[tmp[i].size()] = tmp[i];
	
	string ans = str[1];
	for(int i = 1; i < m; i++){
		llint a[26], b[26];
		get(a, str[i]), get(b, str[i+1]);
		for(int j = 0; j < 26; j++){
			if(a[j] != b[j]){
				ans += (char)(j+'a');
				break;
			}
		}
	}
	reverse(ans.begin(), ans.end());
	
	cout << "? " << 1 << " " << n << endl;
	for(int i = 0; i < n*(n+1)/2; i++){
		cin >> s;
		for(int j = 0; j < s.size(); j++){
			cnt[(int)s.size()][s[j]-'a']++;
		}
	}
	
	for(int i = 0; i <= n/2; i++) getdif(cnt[i+1], cnt[i], dif[i]);
	if(n%2){
		for(int i = 0; i < 26; i++){
			if(dif[n/2][i] > 0) ans += (char)(i+'a');
		}
	}
	/*for(int i = 0; i <= n/2; i++){
		for(int j = 0; j < 26; j++) cout << dif[i][j] << " "; cout << endl;
	}*/
	for(int i = n/2; i >= 1; i--){
		llint d[26];
		getdif(dif[i-1], dif[i], d);
		d[ans[i-1]-'a']--;
		for(int i = 0; i < 26; i++){
			if(d[i] > 0) ans += (char)(i+'a');
		}
	}
	cout << "! " << ans << endl;
	
	return 0;
}