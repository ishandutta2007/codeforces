#include <iostream>
#include <string>
#include <algorithm>
#define llint long long

using namespace std;

llint Q;
string s, t;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int z = 0; z < Q; z++){
		cin >> t >> s;
		sort(t.begin(), t.end());
		int S = s.size(), T = t.size();
		for(int i = 0; i+T-1 < S; i++){
			string u = s.substr(i, T);
			sort(u.begin(), u.end());
			if(t == u){
				cout << "YES" << endl;
				goto end;
			}
		}
		cout << "NO" << endl;
		end:;
	}
	
	return 0;
}