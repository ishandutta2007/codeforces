#include <bits/stdc++.h>
using namespace std;

int x, y;
int main()
{
	cin >> x >> y;
	int i = 1;
	while(1)
	{
		if(i % 2 == 1)
		{
			if(x >= 2 && y >= 2) {x -= 2, y -= 2, i ++; continue;}
			if(x >= 1 && y >= 12) {x --, y -= 12, i ++; continue;}
			if(y >= 22) {y -= 22; i ++; continue;}
			cout << "Hanako";
			return 0;
		}
		else
		{
			if(y >= 22) {y -= 22; i ++; continue;}
			if(x >= 1 && y >= 12) {x --, y -= 12, i ++; continue;}
			if(x >= 2 && y >= 2) {x -= 2, y -= 2, i ++; continue;}
			cout << "Ciel";
			return 0;
		}
	}
	return 0;
}