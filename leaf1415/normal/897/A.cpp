#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int n, m;
	string S;
	
	cin >> n >> m;
	cin >> S;
	
	int l, r; char c1, c2;
	for(int i = 0; i < m; i++){
		cin >> l >> r >> c1 >> c2;
		l--, r--;
		for(int j = l; j <= r; j++){
			if(S[j] == c1) S[j] = c2;
		}
	}
	
	cout << S << endl;
	return 0;
}