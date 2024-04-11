#include <iostream>
#include <string>
#include <set>

using namespace std;

string s;
int n;
int p;
int ans[2005];

int main(void)
{
	cin >> n;
	cin >> p;
	cin >> s;
	
	for(int i = 0; i < s.size(); i++) ans[i] = -1;
	
	for(int i = 0; i < p; i++){
		set<int> ss;
		for(int j = i; j < s.size(); j += p){
			if(s[j] == '0') ss.insert(0);
			if(s[j] == '1') ss.insert(1);
		}
		if(ss.size() >= 2){
			goto ok;
		}
		int pos = -1;
		for(int j = i; j < s.size(); j += p){
			if(s[j] == '.'){
				if(pos == -1){
					if(ss.count(0)){
						ans[j] = 1;
						goto ok;
					}
					else if(ss.count(1)){
						ans[j] = 0;
						goto ok;
					}
					pos = j;
				}else{
					ans[pos] = 1;
					ans[j] = 0;
					goto ok;
				}
			}
		}
	}
		
	cout << "No" << endl;
	return 0;
	
	ok:;
	for(int i = 0; i < s.size(); i++){
		if(ans[i] != -1) continue;
		if(s[i] == '0') ans[i] = 0;
		if(s[i] == '1') ans[i] = 1;
		if(s[i] == '.') ans[i] = 0;
	}
	for(int i = 0; i < s.size(); i++) cout << ans[i];
	cout << endl;
	return 0;
}