#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

struct Result {
	int score;
	int goals;
	int lost;
	string name;
};

bool operator < (Result a, Result b) {
	if (a.score != b.score)
		return a.score > b.score;
	if (a.goals - a.lost != b.goals - b.lost)
		return a.goals - a.lost > b.goals - b.lost;
	return a.goals > b.goals;
}

Result results[50];

map<string, int> teams;

int n;

vector<string> split(string s, char c) {
	vector<string> v;
	string a = "";
	for (int i = 0; i < (int) s.size(); ++i) {
		if (s[i] == c) {
			if (a != "")
				v.push_back(a);
			a = "";
		} else {
			a += s[i];
		}
	}
	if (a != "")
		v.push_back(a);
	return v;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> results[i].name;
		teams[results[i].name] = i;
	}
	for (int i = 0; i < (n * (n - 1)) / 2; ++i) {
		string names, scores;
		cin >> names >> scores;
		vector<string> vNames = split(names, '-');
		vector<string> vScore = split(scores, ':');
		string teamA = vNames[0], teamB = vNames[1];
		int scoreA = atoi(vScore[0].c_str()), scoreB = atoi(vScore[1].c_str());
		if (scoreA > scoreB)
			results[teams[teamA]].score += 3;
		else if (scoreA == scoreB) {
			results[teams[teamA]].score += 1;
			results[teams[teamB]].score += 1;
		} else {
			results[teams[teamB]].score += 3;
		}
		results[teams[teamA]].goals += scoreA;
		results[teams[teamB]].goals += scoreB;
		results[teams[teamB]].lost += scoreA;
		results[teams[teamA]].lost += scoreB;
	}
	sort(results, results + n);
	vector<string> advancers;
	for (int i = 0; i < n / 2; ++i) {
		advancers.push_back(results[i].name);
	}
	sort(ALL(advancers));
	for (int i = 0; i < n / 2; ++i) {
		cout << advancers[i] << "\n";
	}
}