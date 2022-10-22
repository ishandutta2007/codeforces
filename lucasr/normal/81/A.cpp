#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

#define all(x) x.begin(),x.end()
#define FOR(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();++it)
#define bits(x) __builtin_popcount(x)

string input;

int main(){
	cin>>input;
	stack<char> s;
	
	for (int i=0;i<input.length();i++) {
		if (!s.empty() && s.top() == input[i]) {
			s.pop();
		} else {
			s.push(input[i]);
		}
	}
	vector<char> list;
	while (!s.empty()) {
		list.push_back(s.top());
		s.pop();
	}
	for (int i=(int)list.size()-1;i>=0;i--) cout<<list[i];
	cout<<endl;
	
	return 0;
}