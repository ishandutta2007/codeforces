#include <iostream>
#include <string>
#include <vector>
#include <utility>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

int n;
string s[100005];
vector<int> vec[1000005][5], vec2[1000005];
string c = "aiueo";
vector<P> match, match2;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> s[i];
	
	for(int i = 1; i <= n; i++){
		int cnt = 0, v;
		for(int j = 0; j < s[i].size(); j++){
			for(int k = 0; k < 5; k++){
				if(s[i][j] == c[k]){
					cnt++;
					v = k;
					break;
				}
			}
		}
		//cout << s[i] << " " << cnt << endl;
		vec[cnt][v].push_back(i);
	}
	
	for(int i = 0; i < 1000005; i++){
		for(int j = 0; j < 5; j++){
			for(int k = 0; k < vec[i][j].size(); k+=2){
				if(k+1 < vec[i][j].size()){
					match.push_back(P(vec[i][j][k], vec[i][j][k+1]));
				}else{
					vec2[i].push_back(vec[i][j][k]);
				}
			}
		}
	}
	
	for(int i = 0; i < 1000005; i++){
		for(int j = 0; j < vec2[i].size(); j+=2){
			if(j+1 < vec2[i].size()){
				match2.push_back(P(vec2[i][j], vec2[i][j+1]));
			}
		}
	}
	
	int ans =  min(match.size(), (match2.size() + match.size())/2);
	for(int i = ans; i < match.size(); i++) match2.push_back(match[i]);
	cout << ans << endl;
	for(int i = 0; i < ans; i++){
		cout << s[match2[i].first] << " " << s[match[i].first] << "\n";
		cout << s[match2[i].second] << " " << s[match[i].second] << "\n";
	}
	flush(cout);
	
	return 0;
}