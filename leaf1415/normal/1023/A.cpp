#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
string s, rs, t, rt;

int main(void)
{
	cin >> n >> m;
	cin >> s >> t;
	rs = s, rt =  t;
	reverse(rs.begin(), rs.end());
	reverse(rt.begin(), rt.end());

	
	int pos = -1;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '*') pos = i;
	}
	if(pos == -1){
		if(s == t) cout << "YES" << endl;
		else cout << "NO" << endl;
		return 0;
	}
	
	int rpos;
	for(int i = 0; i < s.size(); i++){
		if(rs[i] == '*') rpos = i;
	}
	
	if(t.size() >= pos && s.substr(0, pos) == t.substr(0, pos) 
		&& rs.substr(0, rpos) == rt.substr(0, rpos) && s.size()-1 <= t.size()){
		cout << "YES" << endl;
	}else cout << "NO" << endl;
	return 0;
}