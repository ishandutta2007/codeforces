#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int T;
string s;
int cnt[26];

bool check(string s)
{
	for(int i = 1; i < s.size(); i++){
		if(abs(s[i] - s[i-1]) == 1) return false;
	}
	return true;
}

int main(void)
{
	cin >> T;
	for(int k = 0; k < T; k++){
		cin >> s;
		for(int i = 0; i < 26; i++) cnt[i] = 0;
		for(int i = 0; i < s.size(); i++) cnt[s[i]-'a']++;
		sort(s.begin(), s.end());
		
		string t = s;
		t.erase(unique(t.begin(), t.end()), t.end());
		if(t.size() == 1){
			cout << s << endl;
			continue;
		}
		if(t.size() == 2){
			if(check(s)) cout << s << endl;
			else cout << "No answer" << endl;
			continue;
		}
		if(t.size() == 3){
			string u;
			for(int j = 0; j < cnt[t[0]-'a']; j++) u += t[0];
			for(int j = 0; j < cnt[t[2]-'a']; j++) u += t[2];
			for(int j = 0; j < cnt[t[1]-'a']; j++) u += t[1];
			if(check(u)){
				cout << u << endl;
				continue;
			}
			u = "";
			for(int j = 0; j < cnt[t[1]-'a']; j++) u += t[1];
			for(int j = 0; j < cnt[t[0]-'a']; j++) u += t[0];
			for(int j = 0; j < cnt[t[2]-'a']; j++) u += t[2];
			if(check(u)){
				cout << u << endl;
				continue;
			}
			cout << "No answer" << endl;
			continue;
		}
		if(t.size() == 4){
			string u;
			for(int j = 0; j < cnt[t[2]-'a']; j++) u += t[2];
			for(int j = 0; j < cnt[t[0]-'a']; j++) u += t[0];
			for(int j = 0; j < cnt[t[3]-'a']; j++) u += t[3];
			for(int j = 0; j < cnt[t[1]-'a']; j++) u += t[1];
			cout << u << endl;
			continue;
		}
		if(t.size() >= 5){
			string u;
			for(int i = 0; i < t.size(); i+=2){
				for(int j = 0; j < cnt[t[i]-'a']; j++) u += t[i];
			}
			for(int i = 1; i < t.size(); i+=2){
				for(int j = 0; j < cnt[t[i]-'a']; j++) u += t[i];
			}
			cout << u << endl;
			continue;
		}
	}
	return 0;
}