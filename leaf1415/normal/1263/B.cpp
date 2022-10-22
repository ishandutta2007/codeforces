#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <vector>
#define llint long long

using namespace std;
typedef pair<string, int> P;

llint T;
llint n;
string s[15];
map<string, vector<int> > mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 0; i < n; i++) cin >> s[i];
		
		mp.clear();
		for(int i = 0; i < n; i++) mp[s[i]].push_back(i);
		
		bool used[10];
		for(int j = 0; j < 10; j++) used[j] = false;
		for(int i = 0; i < n; i++) used[s[i][0]-'0'] = true;
		
		llint ans = 0;
		for(auto it = mp.begin(); it != mp.end(); it++){
			vector<int> &vec = it->second;
			if(vec.size() == 1) continue;
			for(int j = 1; j < vec.size(); j++){
				ans++;
				for(int k = 0; k < 10; k++){
					if(!used[k]){
						used[k] = true;
						s[vec[j]][0] = k+'0';
						break;
					}
				}
			}
		}
		cout << ans << endl;
		for(int i = 0; i < n; i++) cout << s[i] << endl;
	}
	return 0;
}