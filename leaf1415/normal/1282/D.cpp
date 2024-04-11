#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n;
char ans[305];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	llint res;
	cout << "a" << endl;
	cin >> res;
	if(res == 0) return 0;
	n = res+1;
	
	if(n > 300){
		for(int i = 1; i <= 300; i++) cout << "b";
		cout << endl;
		cin >> res;
		return 0;
	}
	
	for(int i = 1; i <= n; i++) cout << "a";
	cout << endl;
	cin >> res;
	if(res == n){
		for(int i = 1; i <= n-1; i++) cout << "b";
		cout << endl;
		cin >> res;
		return 0;
	}
	llint pre = res;
	
	for(int i = n; i >= 1; i--){
		for(int j = 1; j <= i-1; j++) cout << "a";
		cout << "b";
		for(int j = i+1; j <= n; j++) cout << ans[j];
		cout << endl;
		
		cin >> res;
		if(res == 0) return 0;
		if(res > pre) ans[i] = 'a';
		else{
			ans[i] = 'b';
			pre = res;
		}
	}
	
	return 0;
}