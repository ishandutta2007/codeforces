#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)

using namespace std;

llint T;
llint n;
string s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> s;
		string a, b; bool flag = false;
		for(int i = 0; i < n; i++){
			if(s[i] == '0'){
				a += '0', b += '0';
			}
			if(s[i] == '1'){
				if(!flag){
					a += '0', b += '1';
					flag = true;
				}
				else{
					a += '1', b += '0';
				}
			}
			if(s[i] == '2'){
				if(!flag){
					a += '1', b += '1';
				}
				else{
					a += '2', b += '0';
				}
			}
		}
		cout << a << "\n";
		cout << b <<"\n";
	}
	flush(cout);
	
	return 0;
}