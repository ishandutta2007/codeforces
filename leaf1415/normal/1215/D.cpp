#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n;
string s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> s;
	
	llint pcnt = 0, ncnt = 0, sum = 0;
	for(int i = 0; i < n; i++){
		if(s[i] != '?'){
			if(i < n/2) sum += (s[i]-'0') * 2;
			else sum -= (s[i]-'0') * 2;
		}
		else{
			if(i < n/2) sum += 9;
			else sum -= 9;
		}
	}
	if(sum == 0) cout << "Bicarp" << endl;
	else cout << "Monocarp" << endl;
	
	return 0;
}