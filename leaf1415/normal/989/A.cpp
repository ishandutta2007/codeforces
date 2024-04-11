#include <iostream>
#include <string>

using namespace std;

string s;
int d[105];

int main(void)
{
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'A') d[i] = 1;
		if(s[i] == 'B') d[i] = 2;
		if(s[i] == 'C') d[i] = 4;
	}
	
	for(int i = 1; i < s.size()-1; i++){
		if((d[i] | d[i+1] | d[i-1]) == 7){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" <<endl;
	
	return 0;
}