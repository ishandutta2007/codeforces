#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int arrow[26];
	int to[26];
	int exists[26];
	for(int i = 0; i < 26; i++){
		arrow[i] = -1;
		to[i] = -1;
		exists[i] = -1;
	}
	for(int i = 0; i < n; i++){
		string a;
		cin >> a;
		for(int j = 0; j < a.size(); j++){
			exists[a[j]-'a'] = 1;
		}
		for(int j = 1; j < a.size(); j++){
			to[a[j]-'a'] = 1;
			arrow[a[j-1]-'a'] = a[j]-'a';
		}
	}
	for(int i = 0; i < 26; i++){
		if(exists[i] == 1 && to[i] == -1){
			char b = i + 'a';
			cout << b;
			while(arrow[b-'a'] != -1){
				b = arrow[b-'a']+'a';
				cout << b;
			}
		}
	}
	cout << endl;
	return 0;
}