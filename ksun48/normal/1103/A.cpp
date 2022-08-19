#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	string s;
	cin >> s;
	int c0 = 0;
	int c1 = 0;
	for(char x : s){
		if(x == '0'){
			vector<int> xv = {0, 2};
			vector<int> yv = {0, 0};
			int j = c0 % 2;
			cout << xv[j] + 1 << " " << yv[j] + 1 << '\n';
			c0 ++;
		} else if(x == '1'){
			vector<int> xv = {0, 1, 2, 3};
			vector<int> yv = {2, 2, 2, 2};
			int j = c1 % 4;
			cout << xv[j] + 1 << " " << yv[j] + 1 << '\n';
			c1 ++;
		}
	}
}