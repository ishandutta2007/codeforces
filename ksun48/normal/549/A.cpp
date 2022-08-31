#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n, m;
	cin >> n >> m;
	string stuff[n];
	int num = 0;
	for(int i = 0; i < n; i++) cin >> stuff[i];
	for(int i = 0; i+1 < n; i++){
		for(int j = 0; j+1 < m; j++){
			int freq[26];
			for(int k = 0; k < 26; k++){
				freq[k] = 0;
			}
			freq[0]--;
			freq[2]--;
			freq[4]--;
			freq[5]--;
			freq[stuff[i][j]-'a']++;
			freq[stuff[i+1][j]-'a']++;
			freq[stuff[i][j+1]-'a']++;
			freq[stuff[i+1][j+1]-'a']++;
			int yes = 1;
			for(int r = 0; r < 26; r++) if(freq[r] != 0) yes = 0;
			if(yes) num++;
		}
	}
	cout << num << endl;

}