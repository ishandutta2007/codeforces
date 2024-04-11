#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	stack<char> st;
	st.push(s[0]);
	for(int i = 1;i < s.size();++i) {
		if(s[i] != st.top() && st.top() != 'D' && s[i] != 'D')  st.pop(),st.push('D');
		else st.push(s[i]);  
	}
	cout << st.size();
}