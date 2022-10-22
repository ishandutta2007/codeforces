#include <iostream>
#include <string>
#define llint long long

using namespace std;

llint n, m;
string s, t;
llint cnt[26];
llint num[200005][26];

bool check(llint x)
{
	if(x < 0) return false;
	for(int i = 0; i < 26; i++) if(num[x][i] < cnt[i]) return false;
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> s >> m;
	
	for(int i = 0; i < s.size(); i++){
		cnt[s[i]-'a']++;
		for(int j = 0; j < 26; j++) num[i][j] = cnt[j];
	}
	
	for(int q = 0; q < m; q++){
		cin >> t;
		for(int i = 0; i < 26; i++) cnt[i] = 0;
		for(int i = 0; i < t.size(); i++) cnt[t[i]-'a']++;
		
		llint ub = (llint)s.size()-1, lb = -1, mid;
		while(ub-lb>1){
			mid = (ub+lb)/2;
			if(check(mid)) ub = mid;
			else lb = mid;
		}
		cout << ub+1 << "\n";
	}
	flush(cout);
	
	return 0;
}