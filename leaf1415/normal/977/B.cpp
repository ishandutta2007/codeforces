#include <iostream>
#include <string>

using namespace std;

int n;
string s;
int cnt[26][26];

int main(void)
{
	cin >> n;
	cin >> s;
	for(int i = 0; i < n-1; i++){
		cnt[s[i]-'A'][s[i+1]-'A']++;
	}
	
	int val = 0, max_i, max_j;
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < 26; j++){
			if(val < cnt[i][j]){
				val = cnt[i][j];
				max_i = i;
				max_j = j;
			}
		}
	}
	cout << (char)(max_i + 'A') << (char)(max_j + 'A') << endl;
	return 0;
}