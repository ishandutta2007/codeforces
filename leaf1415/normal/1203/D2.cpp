#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#define llint long long

using namespace std;

string s, t;
llint lpos[200005], rpos[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s >> t;
	
	int nx = 0;
	for(int i = 0; i < s.size(); i++){
		if(nx < t.size() && s[i] == t[nx]) lpos[nx] = i, nx++;;
	}
	nx = t.size()-1;
	for(int i = (int)s.size()-1; i >= 0; i--){
		if(nx >= 0 && s[i] == t[nx]) rpos[nx] = i, nx--;
	}
	
	llint n = t.size();
	llint ans = max((int)s.size()-1 - lpos[n-1], rpos[0]);
	for(int i = 0; i < (int)n-1; i++) ans = max(ans, rpos[i+1] - lpos[i] - 1);
	cout << ans << endl;
	
	return 0;
}