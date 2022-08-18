/*
*/

//#pragma comment(linker, "/STACK:16777216")
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

const int N = 300000;

using namespace std;

int n, d, h;
vector<pair<int, int> > e;

void add_edge(int a, int b)
{
	e.push_back(make_pair(a, b));
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> d >> h;

	if (d == 1)
	{
		if (n > 2)
		{
			cout << -1 << endl;
			return 0;
		}
		cout << 1 << " " << 2 << endl;
		return 0;
	}

	if (h == 1 && d == 2)
	{
		for (int i = 2; i <= n; i++)
		{
			cout << 1 << " " << i << "\n";
		}
		return 0;
	}

	if (d > 2 * h)
	{
		cout << -1 << endl;
		return 0;
	}

	int left_side = h;
	int fu = 2;
	for (int i = 1; i <= left_side; i++)
	{
		add_edge(fu-1, fu);
		++fu;
	}
	int right_side = d - h;
	for (int i = 1; i <= right_side; i++)
	{
		int prev;
		if (i == 1)
			prev = 1;
		else
			prev = fu - 1;
		add_edge(prev, fu);
		++fu;
	}
	while (fu <= n)
	{
		add_edge(2, fu);
		++fu;
	}

	for (int i = 0; i < e.size(); i++)
	{
		cout << e[i].first << " " << e[i].second << "\n";
	}

	cin.get(); cin.get();
	return 0;
}