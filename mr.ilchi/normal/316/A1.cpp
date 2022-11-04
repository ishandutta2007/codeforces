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

bool mark[100];
string s;

int main(){
	cin >> s;
	LL cur = 1;
	int cnt = 0, c = 10;
	if (s[0]=='?') cur = 9;
	if (isupper(s[0])){
		mark[s[0]-'A'] = true;
		cur = 9;
		c = 9;
	}
	for (int i=1; i<(int)s.size(); i++){
		if (s[i]=='?'){
			cnt++;
		}else if (isupper(s[i])){
			if (!mark[s[i]-'A']){
				mark[s[i]-'A'] = true;
				cur = cur * c;
				c--;
			}
		}
	}
	cout << cur;
	for (int i=0; i<cnt; i++)
		cout << 0;
	cout << endl;
	return 0;
}