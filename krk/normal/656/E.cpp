#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

const int Maxn = 10;

string s;
int n;
int D[Maxn][Maxn];
vector <int> res;

void Read(int row)
{
    s = "";
	getline(cin, s);
	s += " 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000";
	stringstream ss(s);
	ss >> D[row][0]; ss >> D[row][1]; ss >> D[row][2];
	ss >> D[row][3]; ss >> D[row][4]; ss >> D[row][5];
	ss >> D[row][6]; ss >> D[row][7]; ss >> D[row][8];
	ss >> D[row][9];
}

void T4(int k, int i, int j)
{
	D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
}

void T3(int k, int i)
{
	T4(k, i, 0); T4(k, i, 1); T4(k, i, 2); T4(k, i, 3); T4(k, i, 4);
	T4(k, i, 5); T4(k, i, 6); T4(k, i, 7); T4(k, i, 8); T4(k, i, 9);
}

void T2(int k)
{
	T3(k, 0); T3(k, 1); T3(k, 2); T3(k, 3); T3(k, 4);
	T3(k, 5); T3(k, 6); T3(k, 7); T3(k, 8); T3(k, 9);
}

void T1()
{
	T2(0); T2(1); T2(2); T2(3); T2(4);
	T2(5); T2(6); T2(7); T2(8); T2(9);
}

void R3(int i, int j)
{
	res.push_back(D[i][j]);
}

void R2(int i)
{
	R3(i, 0); R3(i, 1); R3(i, 2); R3(i, 3); R3(i, 4);
	R3(i, 5); R3(i, 6); R3(i, 7); R3(i, 8); R3(i, 9);
}

void R1()
{
	R2(0); R2(1); R2(2); R2(3); R2(4);
	R2(5); R2(6); R2(7); R2(8); R2(9);
}

int main()
{
	scanf("%d", &n); getline(cin, s);
	Read(0); Read(1); Read(2);
	Read(3); Read(4); Read(5);
	Read(6); Read(7); Read(8);
	Read(9);
	T1();
	R1();
	sort(res.begin(), res.end());
	printf("%d\n", res[int(res.size()) - 1 - (10 - n) * (n + 10)]);
	return 0;
}