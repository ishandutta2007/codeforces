#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

typedef pair <int, int> ii;

int a;
string lin;
int pnt;
vector <ii> seq;
int res;

void insertNext()
{
	bool neg = lin[pnt] == '-';
	if (lin[pnt] == '-' || lin[pnt] == '+') pnt++;
	int res = 1;
	if (isdigit(lin[pnt])) {
		res = 0;
		while (pnt < lin.length() && isdigit(lin[pnt])) {
			res = 10 * res + lin[pnt] - '0'; pnt++;
		}
		pnt++;
	}
	if (neg) res = -res;
	if (lin[pnt] == '+') seq.push_back(ii(res, 0));
	else seq.push_back(ii(res, 1));
	pnt += 3;
}


int main()
{
	cin >> a >> lin;
	while (pnt < lin.length())
		insertNext();
	sort(seq.begin(), seq.end());
	for (int i = 0; i < seq.size(); i++)
		if (seq[i].second == 0) res += seq[i].first * ++a;
		else res += seq[i].first * a++;
	printf("%d\n", res);
	return 0;
}