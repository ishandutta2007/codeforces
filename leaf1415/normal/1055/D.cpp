#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n;
string s[3005], t[3005];
int flcp[3005], blcp[3005];
vector<string> fvec, bvec;

int lcp(string s, string t)
{
	for(int i = 0; i < s.size(); i++){
		if(s[i] != t[i]) return i;
	}
	return s.size();
}

string get(vector<string> &vec)
{
	string ret;
	for(int i = 0; ; i++){
		for(int j = 0; j < vec.size(); j++){
			if((int)vec[j].size() == i) goto end;
			if(vec[j][i] != vec[0][i]) goto end;
		}
		ret += vec[0][i];
	}
	end:;
	return ret;
}

void Z_algorithm(string s, int z[])
{
	z[0] = s.size();
	
	int x = 0, y = 0;
	for(int i = 1; i < s.size(); i++){
		if(i > y){
			z[i] = 0;
			for(int j = 0; j < s.size(); j++){
				if(i+j > s.size() || s[i+j] != s[j]) break;
				z[i]++;
			}
			x = i, y = i + z[i] - 1;
		}
		else if(i + z[i-x] <= y) z[i] = z[i-x];
		else{
			z[i] = y-i+1;
			for(int j = y-i+1; j < s.size(); j++){
				if(i+j > s.size() || s[i+j] != s[j]) break;
				z[i]++;
			}
			x = i, y = i + z[i] - 1;
		}
	}
}

int z[6005];
int search(string s, string t)
{
	string tmp = t + "#" + s;
	Z_algorithm(tmp, z);
	
	for(int i = t.size()+1; i < tmp.size(); i++){
		if(z[i] == t.size()) return i - ((int)t.size()+1);
	}
	return -1;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> s[i];
	for(int i = 1; i <= n; i++) cin >> t[i];
	
	for(int i = 1; i <= n; i++){
		string revs = s[i], revt = t[i];
		reverse(revs.begin(), revs.end());
		reverse(revt.begin(), revt.end());
		flcp[i] = lcp(s[i], t[i]);
		blcp[i] = lcp(revs, revt);
	}
	
	string S, T;
	for(int i = 1; i <= n; i++){
		if(flcp[i] == s[i].size()) continue;
		S = s[i].substr(flcp[i], (int)s[i].size()-(flcp[i]+blcp[i]));
		T = t[i].substr(flcp[i], (int)t[i].size()-(flcp[i]+blcp[i]));
		break;
	}
	
	for(int i = 1; i <= n; i++){
		if(flcp[i] == (int)s[i].size()) continue;
		string ss = s[i].substr(flcp[i], (int)s[i].size()-(flcp[i]+blcp[i]));
		string tt = t[i].substr(flcp[i], (int)t[i].size()-(flcp[i]+blcp[i]));
		if(S != ss || T != tt){
			cout << "NO" << endl;
			return 0;
		}
	}
	
	for(int i = 1; i <= n; i++){
		if(flcp[i] == s[i].size()) continue;
		string tmp;
		tmp = s[i].substr(0, flcp[i]);
		reverse(tmp.begin(), tmp.end());
		fvec.push_back(tmp);
		tmp = s[i].substr((int)s[i].size() - blcp[i]);
		bvec.push_back(tmp);
	}
	
	string pre = get(fvec), suf = get(bvec);
	reverse(pre.begin(), pre.end());
	S = pre + S + suf, T = pre + T + suf;
	
	for(int i = 1; i <= n; i++){
		int p = search(s[i], S);
		if(p == -1) continue;
		for(int j = 0; j < T.size(); j++) s[i][p+j] = T[j];
		if(s[i] != t[i]){
			cout << "NO" << endl;
			return 0;
		}
	}
	
	cout << "YES" << endl;
	cout << S << endl;
	cout << T << endl;
	
	return 0;
}