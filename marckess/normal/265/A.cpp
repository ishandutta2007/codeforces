#include <iostream>
#include <string>

using namespace std;

int main(){
	string s,s1;
	int j = 0;
	cin >> s1 >> s;
	for(int i=0; i< s.size(); i++){
		if(s[i] == s1[j])
			j++;
	}
	cout << j+1;
	
}