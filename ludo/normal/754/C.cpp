#include<bits/stdc++.h>

using namespace std;

const int MAX = 110;

using pii = pair<int, int>;

int nnames;
map<string, int> nameIdx;
string names[MAX];

int nmsg, sender[MAX];
string msg[MAX];

vector<pii> possible[MAX]; // which senders are possible at this point, with which previously?

bool isWordCh(char ch)
{
	if ('a' <= ch && ch <= 'z') return true;
	if ('A' <= ch && ch <= 'Z') return true;
	if ('0' <= ch && ch <= '9') return true;
	return false;
}

void run()
{
	// init:
	nameIdx.clear();
	for (int i = 0 ; i < MAX; i++) possible[i].clear();

	cin >> nnames;
	for (int i = 0; i < nnames; i++) {
		cin >> names[i];
		nameIdx[names[i]] = i;
	}
	cin >> nmsg;
	getline(cin, msg[0]); // remove newline
	for (int i = 1; i <= nmsg; i++) {
		getline(cin, msg[i]);
		int splitIdx = msg[i].find(':');
		assert(splitIdx != string::npos);
		if (splitIdx == 1 && msg[i][0] == '?') {
			sender[i] = -1;
		} else {
			sender[i] = nameIdx[msg[i].substr(0, splitIdx)];
		}
		msg[i] = msg[i].substr(splitIdx + 1);
	}


	// for (int i = 0; i < nnames; i++) {
	possible[0].push_back(pii(-1, -1));
	// }

	for (int m = 1; m <= nmsg; m++) {
		if (sender[m] >= 0) {
			for (int i = 0, N = possible[m - 1].size(); i < N; i++) {
				if (possible[m - 1][i].first != sender[m]) {
					possible[m].push_back(pii(sender[m], i));
					break;
				}
			}
			continue;
		}

		// sender is unknown
		for (int i = 0; i < nnames; i++) {
			// cerr << "MSG " << m << " " << i
			// if (msg[m].find(names[i]) != string::npos) continue;

			bool inStr = false;
			int slen = names[i].size();
			for (int st = 0; st + slen <= msg[m].size(); st++) {
				if (st > 0 && isWordCh(msg[m][st - 1])) continue;
				if (st + slen < msg[m].size() && isWordCh(msg[m][st + slen])) continue;

				bool eq = true;
				for (int j = 0; j < slen; j++) {
					eq &= msg[m][st + j] == names[i][j];
					if (!eq) break;
				}
				// cerr << m << " " << i << " " << st << ": " << eq << endl;
				inStr |= eq;
				if (inStr) break;
			}
			// cerr << "IS IN STR"  << inStr << endl;
			if (inStr) continue;

			// not found in message.
			int j = 0, N = possible[m - 1].size();
			for (j = 0; j < N; j++) { // max loops: 2
				// cerr << possible[m - 1][j].first << ", " << possible[m - 1][j].second << endl;
				if (possible[m - 1][j].first != i) break;
			}
			// cerr << "Unused name " << names[i] << ": " << j << endl;
			if (j == N) continue;
			possible[m].push_back(pii(i, j));
		}

		/* cerr << m << ": ";
		for (pii pr : possible[m]) {
			cerr << pr.first << ", ";
		}
		cerr << endl;*/
	}

	if (possible[nmsg].empty()) {
		cout << "Impossible" << endl;
		return;
	}

	vector<int> values;
	for (int cur = nmsg, curIdx = 0; cur > 0;) {
		pii pr = possible[cur][curIdx];
		values.push_back(pr.first);
		curIdx = pr.second;
		cur--;
	}
	reverse(values.begin(), values.end());
	for (int i = 0; i < nmsg; i++) {
		cout << names[values[i]] << ":" << msg[i + 1] << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int ntc;
	cin >> ntc;
	while (ntc--) run();
	return 0;
}