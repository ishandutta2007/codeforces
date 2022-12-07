#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <utility>

using namespace std;
bool Dead[1100];
int X[1100];
int Y[1100];
int n, GunX, GunY;
void Kill(int j){
	Dead[j] = true;
	for (int i = j+1; i < n; i++)
	{
		if (!Dead[i] && (GunY-Y[j])*(GunX-X[i]) == (GunY-Y[i])*(GunX-X[j]))
			Dead[i] = true;
	}
}
int main()
{
	int count = 0;
	cin >> n >> GunX >> GunY;
	for (int i = 0; i < n; i++)
		cin >> X[i] >> Y[i];
	for (int i = 0; i < n; i++)
	{
		if (!Dead[i])
		{
			Kill(i);
			count++;
		}
	}
	cout << count << endl;
	return 0;
}