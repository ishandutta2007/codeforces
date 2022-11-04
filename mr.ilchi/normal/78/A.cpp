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
 *
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

const string seda= "aieuo";

string s[10];

inline int bakhsh(string s){
	
	int ret=0;

	for (int i=0;i<(int)s.size();i++){
		if (seda.find(s[i])!=seda.npos)
			ret++;
	}

	return ret;
}
/*********************************************/
int main(){
	getline (cin,s[1]);
	getline (cin,s[2]);
	getline (cin,s[3]);

	if (bakhsh(s[1])==5 && bakhsh(s[2])==7 && bakhsh(s[3])==5)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	
	return 0;
}