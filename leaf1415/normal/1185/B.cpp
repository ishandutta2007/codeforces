#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#define llint long long

using namespace std;

int n;
string s, t;
vector<pair<char, int> > vec, vec2;

void calc(string s, vector<pair<char, int> > &vec)
{
	vec.clear();
	int cnt = 0; char pre = s[0];
	for(int i = 0; i < s.size(); i++){
		if(s[i] == pre) cnt++;
		else{
			vec.push_back(make_pair(pre, cnt));
			cnt = 1;
		}
		pre = s[i];
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int q = 0; q < n; q++){
		cin >> s >> t;
		
		s += "#", t += "#";
		calc(s, vec);
		calc(t, vec2);
		
		if(vec.size() != vec2.size()){
			cout << "NO" << "\n";
			continue;
		}
		bool ans = true;
		for(int i = 0; i < vec.size(); i++){
			if(vec[i].first != vec2[i].first) ans = false;
			else if(vec[i].second > vec2[i].second) ans = false;
		}
		if(ans) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	flush(cout);
	return 0;
}