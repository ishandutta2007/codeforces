#include <iostream>
#include <string>

using namespace std;

int main(){
	string s1,s2;
	cin >> s1 >> s2;

	for(int i = 0; i < s1.size(); i++){
		if(s1[i] < 'a')
			s1[i] += 'a' - 'A';
		if(s2[i] < 'a')
			s2[i] += 'a' - 'A'; 
	}

	if(s1.compare(s2) == 0)
		cout << 0;
	else if(s1.compare(s2) > 0)
		cout << 1;
	else
		cout << -1;

	return 0;
}