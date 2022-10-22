#include <iostream>
#include <string>
#include <stack>
#define llint long long

using namespace std;

llint n, x;
string s;
stack<llint> stk;
const llint lim = 1e10;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	llint mul = 1, over = 0, ans = 0;
	for(int i = 0; i < n; i++){
		cin >> s;
		if(s == "for"){
			cin >> x;
			if(mul >= lim) over++;
			else mul *= x, stk.push(x);
		}
		else if(s == "end"){
			if(over) over--;
			else mul /= stk.top(), stk.pop();
		}
		else{
			if(over){
				cout << "OVERFLOW!!!" << endl;
				return 0;
			}
			ans += mul;
			if(ans >= lim){
				cout << "OVERFLOW!!!" << endl;
				return 0;
			}
		}
		if(ans >= (1LL<<32)){
			cout << "OVERFLOW!!!" << endl;
			return 0;
		}
	}
	cout << ans << endl;
	
	return 0;
}