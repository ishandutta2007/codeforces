#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	string name[n+1];
	int ex[n+1];
	int numex = 0;

	map<string, int> curnames;
	for(int i = 1; i <= n; i++){
		cin >> name[i] >> ex[i];
		numex += ex[i];
		curnames[name[i]] = 1;
	}
	int k = 0;
	string empty = "ksun48";
	while(curnames[empty]){
		k++;
		string j;
		int a = k;
		for(int i = 0; i < 6; i++){
			j += ('a' + (a % 26));
			a /= 26;
		}
		empty = j;
	}

	map<string, int> exs;
	map<string, int> nexs;
	vector<string> num;
	string vv = "0";
	num.push_back(vv);

	for(int i = 1; i <= n; i++){
		string f;
		int a = i;
		while(a){
			f += ('0'+(a % 10));
			a /= 10;
		}
		reverse(f.begin(), f.end());
		num.push_back(f);
		if(i <= numex){
			exs[f] = 1;
		} else {
			nexs[f] = 1;
		}
	}

	int state[n+1];

	int v = 0;
	for(int i = 1; i <= n; i++){
		if(exs[name[i]]){
			state[i] = 1;
		} else if(nexs[name[i]]){
			state[i] = 0;
		} else {
			state[i] = -1;
			v++;
		}
	}
	vector<string> ans1, ans2;
	if(v == 0){
		for(int i = 1; i <= n; i++){
			if(state[i] != ex[i]){
				ans1.push_back(name[i]);
				ans2.push_back(empty);
				name[i] = empty;
				state[i] = -1;
				break;
			}
		}
	}

	set<string> unex;
	set<string> unnex;

	vector<int> wrong1, wrong2;
	for(int i = 1; i <= n; i++){
		if(i <= numex){
			unex.insert(num[i]);
		} else {
			unnex.insert(num[i]);
		}
	}

	for(int i = 1; i <= n; i++){
		if(exs[name[i]]){
			unex.erase(name[i]);
		} else if(nexs[name[i]]){
			unnex.erase(name[i]);
		}
	}
	for(int i = 1; i <= n; i++){
		if(state[i] == 0 && ex[i] == 1){
			wrong1.push_back(i);
		} else if(state[i] == 1 && ex[i] == 0){
			wrong2.push_back(i);
		}
	}


	int s1 = 0;
	int s2 = 0;
	while(s1 < wrong1.size() || s2 < wrong2.size()){
		if(s1 < wrong1.size() && !unex.empty()){
			int d = wrong1[s1];
			string f = *unex.begin();
			ans1.push_back(name[d]);
			ans2.push_back(f);
			unex.erase(f);
			unnex.insert(name[d]);
			name[d] = f;
			state[d] = ex[d];
			s1++;
		} else if(s2 < wrong2.size() && !unnex.empty()){
			int d = wrong2[s2];
			string f = *unnex.begin();
			ans1.push_back(name[d]);
			ans2.push_back(f);
			unnex.erase(f);
			unex.insert(name[d]);
			name[d] = f;
			state[d] = ex[d];
			s2++;
		} else {
			break;
		}
	}
	for(int i = 1; i <= n; i++){
		if(state[i] == -1){
			if(ex[i] == 1){
				string f = *unex.begin();
				ans1.push_back(name[i]);
				ans2.push_back(f);
				unex.erase(f);
				name[i] = f;
				state[i] = ex[i];
			} else {
				string f = *unnex.begin();
				ans1.push_back(name[i]);
				ans2.push_back(f);
				unnex.erase(f);
				name[i] = f;
				state[i] = ex[i];
			}
		}
	}

	cout << ans1.size() << endl;
	for(int i = 0; i < ans1.size(); i++){
		cout << "move " << ans1[i] << " " << ans2[i] << endl;
	}
}