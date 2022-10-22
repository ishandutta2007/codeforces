#include <iostream>
#include <string>
#include <map>

using namespace std;

int n;
string s[6];
string S[] = {"Power", "Time", "Space", "Soul", "Reality", "Mind"};
string T[] = {"purple", "green", "blue", "orange", "red", "yellow"};
bool have[6];

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> s[i];
	
	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 6; j++){
			if(s[i] == T[j]){
				have[j] = true;
				cnt++;
				break;
			}
		}
	}
	
	cout << 6 - cnt << endl;
	for(int i = 0; i < 6; i++){
		if(!have[i]) cout << S[i] << endl;
	}
	
	return 0;
}