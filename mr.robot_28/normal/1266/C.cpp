#include<bits/stdc++.h> 
#include<fstream>
using namespace std;
#define int long long

main () {
	int r, c;
	cin >> r >> c;
	if(r == 1 && c == 1)
	{
		cout << 0;
	}
	else if(r == 1)
	{
		for(int i = 0; i < c; i++)
		{
			cout << i + 2 << " ";
		}
	}
	else if(c == 1)
	{
		for(int i = 0; i < r; i++)
		{
			cout << i + 2 << "\n";
		}
	}
	else
	{
		vector <int> b(r + c);
		for(int i = 0; i < r + c; i++)
		{
			b[i] = i + 1;
		}
		for(int i = 0; i < r; i++)
		{
			for(int j = 0; j < c; j++)
			{
				cout << b[i] * b[j + r] << " "; 
			}
			cout << "\n";
		}
	}
    return 0;
}