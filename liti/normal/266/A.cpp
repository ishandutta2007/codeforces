#include <iostream>
using namespace std;

int main(){
	string s;
	int n;
	cin >> n;
	cin >> s;
	string r = "";
	r += s[0];
	int counter= 0;
	for(int i = 1 ; i < s.length() ;i++)
	{
		if ( r[ r.length() - 1] == s[i] )
			counter++;
		else
			r+= s[i];
	}
	cout << counter << endl;
}