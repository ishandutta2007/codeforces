#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef pair <string, string> ss;
typedef pair <int, int> ii;

const int Maxn = 100005;

char tmp[15];
set <string> S;
int n;
string s[Maxn];
int ex[Maxn];
int e;
set <int> A, B;
vector <int> waitA, waitB;
vector <ii> confA, confB;
vector <ss> res;

void Read(string &s)
{
	scanf("%s", tmp); s = tmp;
}

int getNum(const string &s)
{
	if (s[0] == '0') return -1;
	int res = 0;
	for (int i = 0; i < s.length(); i++)
		if ('0' <= s[i] && s[i] <= '9')
			res = 10 * res + int(s[i] - '0');
		else return -1;
	return res;
}

string toString(int num)
{
	stringstream ss; ss << num;
	string s; ss >> s;
	return s;
}

string Get(int from)
{
	string s;
	do {
		s = toString(from);
		from++;
	} while (S.find(s) != S.end());
	return s;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		Read(s[i]); scanf("%d", &ex[i]);
		e += ex[i];
		S.insert(s[i]);
	}
	for (int i = 1; i <= e; i++)
		A.insert(i);
	for (int i = e + 1; i <= n; i++)
		B.insert(i);
	for (int i = 0; i < n; i++) {
		int got = getNum(s[i]);
		if (got == -1 || got <= 0 || got > n)
			if (ex[i] == 1) waitA.push_back(i);
			else waitB.push_back(i);
		else if (ex[i] == 1)
				if (got <= e) A.erase(got);
				else {
					B.erase(got);
					confB.push_back(ii(got, i));
				}
			else if (got > e) B.erase(got);
				 else {
				 	A.erase(got);
				 	confA.push_back(ii(got, i));
				 }
	}
	while (confA.size() > 0 || confB.size() > 0)
		if (confA.size() > 0 && B.size() > 0) {
			res.push_back(ss(s[confA.back().second], toString(*B.begin())));
			A.insert(confA.back().first); confA.pop_back();
			B.erase(B.begin());
		} else if (confB.size() > 0 && A.size() > 0) {
			res.push_back(ss(s[confB.back().second], toString(*A.begin())));
			B.insert(confB.back().first); confB.pop_back();
			A.erase(A.begin());
		} else if (confA.size() > 0) {
			string tmp = Get(100001);
			res.push_back(ss(s[confA.back().second], tmp)); s[confA.back().second] = tmp;
			A.insert(confA.back().first); waitB.push_back(confA.back().second); confA.pop_back();
		} else if (confB.size() > 0) {
			string tmp = Get(100001);
			res.push_back(ss(s[confB.back().second], tmp)); s[confB.back().second] = tmp;
			B.insert(confB.back().first); waitA.push_back(confB.back().second); confB.pop_back();
		}
	for (int i = 0; i < waitA.size(); i++) {
		res.push_back(ss(s[waitA[i]], toString(*A.begin())));
		A.erase(A.begin());
	}
	for (int i = 0; i < waitB.size(); i++) {
		res.push_back(ss(s[waitB[i]], toString(*B.begin())));
		B.erase(B.begin());
	}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("move %s %s\n", res[i].first.c_str(), res[i].second.c_str());
	return 0;
}