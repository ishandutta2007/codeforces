#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

bool isVowel(char a){
	return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
}

string readWord(int k){
	string s; cin >> s;
	string ans = "";
	int tot = 0;
	for (int i = s.length() - 1; i >= 0 && tot < k; --i){
		if (isVowel(s[i])) ++tot;
		ans += s[i];
	}
	if (tot < k){
		cout << "NO" << endl;
		exit(0);
	}
	return ans;
}

string getMode(int k){
	vector<string> v(4);
	for (int i = 0; i < 4; ++i)
		v[i] = readWord(k);

	if (v[0] == v[1] && v[2] == v[3]){
		if (v[0] == v[2]) return "aaaa";
		else return "aabb";
	}
	else if (v[0] == v[2] && v[1] == v[3])
		return "abab";
	else if (v[0] == v[3] && v[1] == v[2])
		return "abba";
	else{
		cout << "NO" << endl;
		exit(0);
	}

	return "THIS IS BAD";
}

string mix(string a, string b){
	if (a == b) return a;
	if (a == "aaaa") return b;
	if (b == "aaaa") return a;
	cout << "NO" << endl;
	exit(0);
	return "THIS IS BAD";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	string mode = "aaaa";
	for (int i = 0; i < n; ++i)
		mode = mix(mode, getMode(k));

	cout << mode << endl;
	return 0;
}