#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint T;
llint n, m;
string s;
llint p[200005];
llint dif[200005];
llint ans[26];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> m;
		cin >> s;
		s = "#" + s;
		for(int i = 1; i <= m; i++) cin >> p[i];
		for(int i = 1; i <= n; i++) dif[i] = 0;
		
		for(int i = 1; i <= m; i++){
			dif[1]++;
			dif[p[i]+1]--;
		}
		
		for(int i = 0; i < 26; i++) ans[i] = 0;
		llint sum = 1;
		for(int i = 1; i <= n; i++){
			sum += dif[i];
			ans[s[i]-'a'] += sum;
		}
		for(int i = 0; i < 26; i++) cout << ans[i] << " "; cout << "\n";
	}
	flush(cout);
	
	return 0;
}