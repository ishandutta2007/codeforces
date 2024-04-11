#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	if (n == 1){
		cout << 1 << endl;
	}	
	else{
		int le = m - 1;
		int ri = n - m;
		
		if (le >= ri)
			cout << m - 1 << endl;			
		else
			cout << m + 1 << endl;
	}
}