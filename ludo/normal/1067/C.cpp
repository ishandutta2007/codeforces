#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int r = N % 3, q = N / 3;
	if (r == 1) cout << "1 -1" << endl;
	else if (r == 2) cout << "1 -1\n2 -2\n";
	
	for (int i = 0; i < q; i++) {
	    cout << "0 " << (i+i) << "\n1 " << (i + i + 1) << "\n2 " << (i + i) << endl;   
	}

	return 0;
}