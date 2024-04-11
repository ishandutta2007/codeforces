#include <iostream>
#include <string>

using namespace std;

int n;
string s;
int cnt[3];

int main(void)
{
	cin >> n;
	cin >> s;
	for(int i = 0; i < n; i++) cnt[s[i]-'0']++;
	
	for(int i = 0; i < n; i++){
		if(cnt[0] < n/3 && s[i] > '0' && cnt[s[i]-'0'] > n/3) cnt[s[i]-'0']--, cnt[0]++, s[i] = '0';
		if(cnt[1] < n/3 && s[i] > '1' && cnt[s[i]-'0'] > n/3) cnt[s[i]-'0']--, cnt[1]++, s[i] = '1';
	}
	for(int i = n-1; i >= 0; i--){
		if(cnt[2] < n/3 && s[i] < '2' && cnt[s[i]-'0'] > n/3) cnt[s[i]-'0']--, cnt[2]++, s[i] = '2';
		if(cnt[1] < n/3 && s[i] < '1' && cnt[s[i]-'0'] > n/3) cnt[s[i]-'0']--, cnt[1]++, s[i] = '1';
	}
	
	cout << s << endl;
	return 0;
}