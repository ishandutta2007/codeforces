#include <iostream>
#include <string>
#include <stdlib.h>
#include <map>

using namespace std;

int n;
int cnt[5][3], cnt2[5][3];
int c[] = {'S', 'L', 'M'};


int main(void)
{
	cin >> n;
	string s;
	for(int i = 0; i < n; i++){
		cin >> s;
		char C = s[s.size()-1];
		for(int j = 0; j < 3; j++){
			if(C == c[j]){
				cnt[s.size()][j]++;
			}
		}
	}
	for(int i = 0; i < n; i++){
		cin >> s;
		char C = s[s.size()-1];
		for(int j = 0; j < 3; j++){
			if(C == c[j]){
				cnt2[s.size()][j]++;
			}
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= 4; i++){
		for(int j = 0; j < 3; j++) ans += abs(cnt[i][j] - cnt2[i][j]);
	}
	cout << ans / 2 << endl;
	return 0;
}