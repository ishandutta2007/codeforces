#include <iostream>
#include <string>
#define llint long long

using namespace std;

llint T;
string a, b, c;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> a >> b >> c;
		bool flag = true;
		for(int i = 0; i < a.size(); i++){
			if(a[i] != c[i] && b[i] != c[i]){
				flag = false;
				break;
			}
		}
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}