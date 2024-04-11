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
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <map>

using namespace std;

int n;
map <string, bool> mark;

int main (){
	mark["ABSINTH"]= true;
	mark["BEER"]= true;
	mark["BRANDY"]= true;
	mark["CHAMPAGNE"]= true;
	mark["GIN"]= true;
	mark["RUM"]= true;
	mark["SAKE"]= true;
	mark["TEQUILA"]= true;
	mark["VODKA"]= true;
	mark["WHISKEY"]= true;
	mark["WINE"]= true;
	cin >> n;
	int res= 0;
	for (int i= 1;i<= n;i ++){
		string s;
		cin >> s;
		if (s[0] > '9')
			res+= mark[s];
		else{
			int tmp= 0, p= 0;
			while (p< (int)s.size ())
				tmp= tmp*10+ s[p ++]-'0';
			if (tmp < 18)
				res ++;
		}
	}
	cout << res << endl;


	return 0;
}