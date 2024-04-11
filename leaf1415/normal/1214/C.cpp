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
	
	cin >> n >> s;
	
	llint mn = 0, h = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '(') h++;
		else h--;
		mn = min(mn, h);
	}
	if(h != 0 || mn <= -2){
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	
	return 0;
}