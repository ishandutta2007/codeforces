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
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const string base = "aeiou";

bool mark[10];
int n,k;
string s[10];

int main(){

	ios_base::sync_with_stdio(false);

	cin >> n >> k;

	mark[1] = mark[2] = mark[3] = mark[4] = true;

	for (int i=1; i<=n; i++){
		for (int j=1; j<=4; j++){
			cin >> s[j];
			int tmp=k;
			for (int z=(int)s[j].size()-1; z>=0; z--) if (base.find(s[j][z])!=base.npos){
				tmp--;
				if (tmp==0){
					s[j] = s[j].substr (z,(int)s[j].size()-z);
					break;
				}
			}
		//		cout << tmp << endl;
			if (tmp!=0){
				cout << "NO" << endl;
				return 0;
			}
		}

		if (s[1]!=s[2] || s[3]!=s[4])
			mark[1] = false;
		if (s[1]!=s[3] || s[2]!=s[4])
			mark[2] = false;
		if (s[1]!=s[4] || s[2]!=s[3])
			mark[3] = false;
		if (s[1]!=s[2] || s[1]!=s[3] || s[1]!=s[4])
			mark[4] = false;
	}

	if (mark[4]) { cout << "aaaa" << endl; return 0; }
	if (mark[1]) { cout << "aabb" << endl; return 0; }
	if (mark[2]) { cout << "abab" << endl; return 0; }
	if (mark[3]) { cout << "abba" << endl; return 0; }

	cout << "NO" << endl;

	return 0;
}