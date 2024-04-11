#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <utility>
#define llint long long

using namespace std;

string s, ans;
stack<int> stk;
bool used[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '0'){
			if(stk.size()){
				used[i] = used[stk.top()] = true;
				stk.pop();
			}
		}
		else stk.push(i);
	}
	for(int i = 0; i < s.size(); i++){
		if(!used[i]) cout << 0;
		else cout << s[i];
	}
	cout << endl;
	
	return 0;
}