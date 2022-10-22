#include <iostream>
#include <string>

using namespace std;

int Q;
int n;
string s;

int main(void)
{
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> n;
		int odd = 0, cnt0 = 0, cnt1 = 0;
		for(int i = 0; i < n; i++){
			cin >> s;
			if(s.size() % 2) odd++;
			for(int j = 0; j < s.size(); j++){
				if(s[j] == '0') cnt0++;
				else cnt1++;
			}
		}
		if(odd == 0 && cnt0 % 2) cout << n-1 << endl;
		else cout << n << endl;
	}
	
	return 0;
}