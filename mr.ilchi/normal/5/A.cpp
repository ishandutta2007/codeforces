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
#include <set>

using namespace std;

string s;
set <string> sit;

int main (){
	int res= 0;
	while (getline (cin, s)){
		if (s[0]== '-')
			sit.erase (s.substr(1,s.size()-1));
		else if (s[0]== '+')
			sit.insert (s.substr(1,s.size()-1));
		else{
			int start= 0;
			while (s[start]!= ':')
				start ++;
			res+= (s.size()-start-1) * sit.size();
		}
	}
	cout << res << endl;

	return 0;
}