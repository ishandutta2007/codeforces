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
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

string s;

int main (){
	cin >> s;
	string p= "hello";
	int k= 0;
	for (int i= 0;i< (int)s.size ();i ++){
		if (s[i]== p[k])
			k ++;
		if (k== p.size ())
			break;
	}
	if (k== p.size ())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}