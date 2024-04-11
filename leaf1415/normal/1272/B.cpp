#include <iostream>
#include <cstdlib>
#include <string>
#define llint long long

using namespace std;

llint Q;
string s;
int l, r, d, u;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> s;
		l = r = d = u = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == 'L') l++;
			if(s[i] == 'R') r++;
			if(s[i] == 'D') d++;
			if(s[i] == 'U') u++;
		}
		l = min(l, r), d = min(d, u);
		r = l, u = d;
		if(l == 0) d = u = min(u, 1);
		if(d == 0) l = r = min(l, 1);
		
		cout << 2*(l+d) << endl;
		for(int i = 0; i < l; i++) cout << "L";
		for(int i = 0; i < u; i++) cout << "U";
		for(int i = 0; i < r; i++) cout << "R";
		for(int i = 0; i < d; i++) cout << "D";
		cout << endl;
	}
	
	return 0;
}