#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;
typedef pair<llint, P> E;

llint n;
string s, t;
llint G[5][5];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	cin >> s >> t;
	
	cout << "YES" << endl;
	
	if(s[0]==s[1] || t[0]==t[1]){
		if(t[0]==t[1]) swap(s, t);
		if(t == "ab" || t == "bc" || t == "ca"){
			for(int i = 0; i < n; i++) cout << "cba"; cout << endl;
		}
		else{
			for(int i = 0; i < n; i++) cout << "abc"; cout << endl;
		}
		return 0;
	}
	
	string p = "abc";
	do{
		if((s[0]==p[0]&&s[1]==p[1]) || (t[0]==p[0]&&t[1]==p[1])) continue;
		if((s[0]==p[1]&&s[1]==p[2]) || (t[0]==p[1]&&t[1]==p[2])) continue;
		
		for(int i = 0; i < n; i++) cout << p[0];
		for(int i = 0; i < n; i++) cout << p[1];
		for(int i = 0; i < n; i++) cout << p[2];
		cout << endl;
		break;
		
	}while(next_permutation(p.begin(), p.end()));
	
	return 0;
}