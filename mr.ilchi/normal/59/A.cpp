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
 */

#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	cin >> s;
	int up=0, low=0;
	for (int i=0;i< (int)s.size();i ++)
		if (s[i]<='Z')
			up ++;
		else
			low ++;
	if (up> low){
		for (int i=0;i< (int)s.size();i ++){
			if (s[i]>= 'a')
				s[i]= (s[i]-'a')+'A';
		}
	}
	else{
		for (int i=0;i< (int)s.size();i ++)
			if (s[i]<='Z')
				s[i]= s[i]-'A'+'a';
	}
	cout << s << endl;
	return 0;
}