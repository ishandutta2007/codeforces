#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int t;
int n;
string nam[Maxn];
map <string, int> ID;
int m;
int send[Maxn];
string text[Maxn], mtext[Maxn];
vector <int> av[Maxn], seq;

bool Less(const int &a, const int &b) { return av[a].size() < av[b].size(); }

bool Gen(int lvl)
{
	if (lvl >= seq.size()) return true;
	for (int i = 0; i < av[seq[lvl]].size(); i++) {
		send[seq[lvl]] = av[seq[lvl]][i];
		if (seq[lvl] > 0 && send[seq[lvl] - 1] == send[seq[lvl]] ||
			seq[lvl] + 1 < m && send[seq[lvl] + 1] == send[seq[lvl]]) {
			send[seq[lvl]] = -1;
			continue;
		}
		if (Gen(lvl + 1)) return true;
		send[seq[lvl]] = -1;
	}
	return false;
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		ID.clear();
		for (int i = 0; i < n; i++) {
			cin >> nam[i]; ID[nam[i]] = i;
		}
		scanf("%d", &m);
		string s; getline(cin, s);
		bool ok = true;
		for (int i = 0; i < m && ok; i++) {
			getline(cin, s);
			int pos = s.find(":");
			string sen = s.substr(0, pos); text[i] = s.substr(pos + 1);
			if (sen == "?") send[i] = -1;
			else if (ID.find(sen) == ID.end()) ok = false;
				 else send[i] = ID[sen];
			mtext[i] = " " + text[i] + " ";
			for (int j = 0; j < mtext[i].length(); j++)
				if (mtext[i][j] == '.' || mtext[i][j] == ',' || mtext[i][j] == '!' || mtext[i][j] == '?') mtext[i][j] = ' ';
			av[i].clear();
			if (send[i] == -1) {
				for (int j = 0; j < n; j++)
					if (mtext[i].find(" " + nam[j] + " ") == string::npos) av[i].push_back(j);
			} else av[i].push_back(send[i]);
		}
		seq.clear();
		for (int i = 0; i < m; i++)
			seq.push_back(i);
		sort(seq.begin(), seq.end(), Less);
		if (ok && Gen(0))
			for (int i = 0; i < m; i++)
				printf("%s:%s\n", nam[send[i]].c_str(), text[i].c_str());
		else printf("Impossible\n");
	}
    return 0;
}