#include <iostream>
#include <string>

using namespace std;

int n;
string s;

bool check(char c)
{
	return c == 'a' ||  c == 'i' ||  c == 'u' ||  c == 'e' ||  c == 'o' ||  c == 'y'; 
}

int main(void)
{
	cin >> n >> s;
	for(int i = 0; i < s.size()-1; i++){
		if(check(s[i]) && check(s[i+1])){
			s.erase(s.begin() + i+1);
			i--;
		}
	}
	
	cout << s << endl;
	return 0;
}