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
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<int,int> Pair;

string s;

inline bool cmp(string a, string b){
	if(a.size()!=b.size())
		return a.size()<b.size();
	for (int i=0;i<(int)a.size();i++){
		if (a[i]!=b[i])
			return a[i]<b[i];
	}
	return true;
}
/***************************************/
int main(){
	cin >> s;
	if (cmp(s,"127")){
		cout << "byte" << endl;
		return 0;
	}
	if (cmp(s,"32767")){
		cout << "short" << endl;
		return 0;
	}

	if (cmp(s,"2147483647")){
		cout << "int" << endl;
		return 0;
	}

	if (cmp(s,"9223372036854775807")){
		cout << "long" << endl;
		return 0;
	}

	cout << "BigInteger" << endl;

	return 0;
}