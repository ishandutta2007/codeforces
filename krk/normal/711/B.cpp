#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 505;

int n;
int B[Maxn][Maxn];
vector <ll> my, his;

bool getRow(int r, ll &sum)
{
	sum = 0;
	bool was = false;
	for (int i = 0; i < n; i++) {
		sum += B[r][i]; was |= B[r][i] == 0;
	}
	return was;
}

bool getCol(int c, ll &sum)
{
	sum = 0;
	bool was = false;
	for (int i = 0; i < n; i++) {
		sum += B[i][c]; was |= B[i][c] == 0;
	}
	return was;
}

bool getDiag1(ll &sum)
{
	sum = 0;
	bool was = false;
	for (int i = 0; i < n; i++) {
		sum += B[i][i]; was |= B[i][i] == 0;
	}
	return was;
}

bool getDiag2(ll &sum)
{
	sum = 0;
	bool was = false;
	for (int i = 0; i < n; i++) {
		sum += B[n - 1 - i][i]; was |= B[n - 1 - i][i] == 0;
	}
	return was;
}

int main()
{
	scanf("%d", &n);
	if (n == 1) { printf("1\n"); return 0; }
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &B[i][j]);
	for (int i = 0; i < n; i++) {
		ll sum;
		if (getRow(i, sum)) my.push_back(sum);
		else his.push_back(sum);
		if (getCol(i, sum)) my.push_back(sum);
		else his.push_back(sum);
	}
	ll sum;
	if (getDiag1(sum)) my.push_back(sum);
	else his.push_back(sum);
	if (getDiag2(sum)) my.push_back(sum);
	else his.push_back(sum);
	sort(my.begin(), my.end()); my.erase(unique(my.begin(), my.end()), my.end());
	sort(his.begin(), his.end()); his.erase(unique(his.begin(), his.end()), his.end());
	if (my.size() >= 2 || his.size() >= 2 || my[0] >= his[0]) printf("-1\n");
	else printf("%I64d\n", his[0] - my[0]);
	return 0;
}