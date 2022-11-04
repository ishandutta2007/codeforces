/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <iomanip>
#include <utility>

using namespace std;

typedef long long LL;
typedef complex<double> point;
typedef long double ldb;
typedef pair<int,int> pii;

const int inf = 1000000000;

string s,ss,t;
int func[200][30];
int dp[200][200][200];

inline int go (int pos1, int pos2, int state){
	if (state == (int)t.size())
		return -inf;
	if (pos1 == (int)s.size() || pos2 == (int)ss.size())
		return 0;
	int &ret = dp[pos1][pos2][state];
	if (ret != -1)
		return ret;
	ret = max(go(pos1+1,pos2,state), go(pos1,pos2+1,state));
	if (s[pos1] == ss[pos2])
		ret = max(ret, go(pos1+1, pos2+1, func[state][s[pos1]-'A']) + 1);
	return ret = max(ret, 0);
}

inline void print (int pos1, int pos2, int state){
	if (pos1 == (int)s.size() || pos2 == (int)ss.size())
		return;
	int &ret = dp[pos1][pos2][state];
	if (ret == 0)
		return;
	if (go(pos1+1,pos2,state) == ret){
		print(pos1+1, pos2, state);
		return;
	}else if (go(pos1,pos2+1,state) == ret){
		print(pos1,pos2+1,state);
		return;
	}
	cout << s[pos1];
	print(pos1+1,pos2+1,func[state][s[pos1]-'A']);
}

int main(){
	cin >> s >> ss >> t;
	for (int i=0; i<(int)t.size(); i++){
		for (char j = 'A'; j<='Z'; j++){
			string temp = t.substr(0, i) + string(1, j);
			while (!temp.empty() && temp!=t.substr(0, (int)temp.size()))
				temp = temp.substr(1);
			func[i][j-'A'] = (int)temp.size();
		}
	}
	memset(dp, -1, sizeof dp);
	int temp = go(0,0,0);
	if (temp == 0)
		cout << 0 << endl;
	else{
		print(0,0,0);
		cout << endl;
	}
	return 0;
}