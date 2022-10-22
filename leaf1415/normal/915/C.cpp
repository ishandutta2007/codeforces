#include <iostream>
#include <string>
#include <algorithm>
#define llint long long

using namespace std;

string a, b, ans;
int cnt[10];

string downCount(int cnt[])
{
	string ret;
	for(int i = 9; i >= 0; i--){
		for(int j = 0; j < cnt[i]; j++) ret += (char)('0' + i);
	}
	return ret;
}

string dfs(int p, int cnt[])
{
	string res;
	if(p == a.size()) return "";
	
	int cnt2[10];
	for(int j = 0; j < 10; j++) cnt2[j] = cnt[j];
	
	for(int i = 9; i >= 0; i--){
		if(cnt[i] <= 0) continue;
		if(i > b[p] - '0') continue;
		if(i < b[p] - '0'){
			cnt2[i]--;
			return (char)('0'+i) + downCount(cnt2);
		}
		cnt2[i]--;
		res = dfs(p+1, cnt2);
		cnt2[i]++;
		if(res == "*") continue;
		return (char)('0'+i) + res;
	}
	return "*";
}

int main(void)
{
	cin >> a >> b;
	for(int i = 0; i < a.size(); i++) cnt[a[i]-'0']++;
	
	if(a.size() < b.size()) ans = downCount(cnt);
	else ans = dfs(0, cnt);
	
	cout << ans << endl;
	return 0;
}