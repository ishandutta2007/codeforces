#include <bits/stdc++.h>
using namespace std;
int a[5][5];
int main()
{
	for(int i = 1; i <= 4; i ++)
		for(int j = 1; j <= 4; j ++)
			cin >> a[i][j];

	for(int i = 1; i <= 4; i ++)
	{
		if(a[i][4] == 0) continue;
		for(int j = 1; j <= 3; j ++) if(a[i][j]) {cout << "YES"; return 0;}
		int k = i + 1;
		if(k > 4) k -= 4;
		if(a[k][1]) {cout << "YES"; return 0;}
		k ++;
		if(k > 4) k -= 4;
		if(a[k][2]) {cout << "YES"; return 0;}
		k ++;
		if(k > 4) k -= 4;
		if(a[k][3]) {cout << "YES"; return 0;}
	}
	cout << "NO";
	return 0;
}