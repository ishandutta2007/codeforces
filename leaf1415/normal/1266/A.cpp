#include <iostream>
#include <string>
#define llint long long

using namespace std;

llint n;
string s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> s;
		llint sum = 0;
		llint even = 0; bool flag = false;
		for(int i = 0; i < s.size(); i++){
			int c = s[i]-'0';
			if(c%2==0) even++;
			if(c==0) flag = true;
			sum += c;
		}
		if(flag && even >= 2 && sum % 3 == 0) cout << "red" << endl;
		else cout << "cyan" << endl;
	}
	
	return 0;
}