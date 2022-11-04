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
 *
 */

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int p[10+2];
string space, s;
vector <string> q[10+2];
set <string> sign;

int main (){
	cin >> n;
	int sumL= 0;
	for (int i= 1;i<= n;i ++){
		cin >> s;
		sumL+= s.size ();
		q[s.size()].push_back (s);
	}
	cin >> space;
	for (int i= 1;i<= 10;i ++){
		sort (q[i].begin(), q[i].end());
		for (int j= 0;j< (int)q[i].size ();j ++)
			sign.insert (q[i][j]+space);
	}
	int len= sumL/(n/2);
	for (int i= 1;i<= n/2;i ++){
		string mini= *sign.begin ();
		sign.erase (mini);
		cout << mini;
		p[mini.size()-1] ++;
		int oth_len= len-mini.size()+1;
		cout << q[oth_len][p[oth_len]] << endl;
		sign.erase (q[oth_len][p[oth_len]++]+ space);
	}

	return 0;
}