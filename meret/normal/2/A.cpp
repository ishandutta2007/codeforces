#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <cassert>

using namespace std;

int main() {
	int n;
	cin >> n;
	map<string, int> score;
	set<string> win;
	vector< pair<string, int> > v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i].first >> v[i].second;
		score[v[i].first] += v[i].second;
	}
	int mx = score.begin()->second;
	for(map<string, int>::iterator it = score.begin(); it != score.end(); ++it)
		mx = max(mx, it->second);
	map<string, int> score2;
	for(int i = 0; i < n; ++i){
		score2[v[i].first] += v[i].second;
		if(score[v[i].first] == mx && score2[v[i].first] >= mx){
			cout << v[i].first << endl;
			return 0;
		}
	}
	assert(false);
}