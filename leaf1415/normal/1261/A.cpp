#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

int T;
int n, k;
string s;
vector<P> ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int z = 0; z < T; z++){
		cin >> n >> k >> s;
		string t;
		for(int i = 0; i < k-1; i++) t += "()";
		for(int i = 0; i < (n-2*(k-1))/2; i++) t += "(";
		for(int i = 0; i < (n-2*(k-1))/2; i++) t += ")";
		
		ans.clear();
		for(llint i = 0; i < n; i++){
			if(s[i] == t[i]) continue;
			int pos;
			for(llint j = i+1; j < n; j++){
				if(s[j] == t[i]){
					pos = j;
					break;
				}
			}
			ans.push_back(P(i, pos));
			reverse(s.begin()+i, s.begin()+pos+1);
		}
		
		cout << ans.size() << endl;
		for(int i = 0; i < ans.size(); i++){
			cout << ans[i].first+1 << " " << ans[i].second+1 << endl;
		}
	}
	
	return 0;
}