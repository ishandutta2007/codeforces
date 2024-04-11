#include <iostream>

using namespace std;

int T, n;
string str;
int count[26];
int deg[26];
bool visited[26];
int letter[26];

int main() {
	cin >> T;
	for(int t = 0; t < T; t++) {
		cin >> str;
		n = str.length();
		for(int i = 0; i < 26; i++) {
			count[i] = 0;
		}
		for(int i = 0; i < n; i++) {
			count[str[i] - 'a']++;
		}
		for(int i = 0; i < 26; i++) {
			deg[i] = 0;
			if(i > 0 && count[i - 1] > 0) deg[i]++;
			if(i < 25 && count[i + 1] > 0) deg[i]++;
			if(count[i] == 0) deg[i] = 0;
		}
		int last = -2;
		bool answer = true;
		for(int i = 0; i < 26; i++) {
			visited[i] = false;
		}
		for(int i = 0; i < 26 && answer; i++) {
			int maxdeg = -1;
			int maxidx = -1;
			for(int j = 0; j < 26; j++) {
				if(!visited[j] && (abs(j - last) > 1 || count[j] == 0) && deg[j] > maxdeg) {
					maxdeg = deg[j];
					maxidx = j;
				}
			}
			if(maxidx == -1) {
				answer = false;
				cout << "No answer" << endl;
			}else {
				letter[i] = maxidx;
				visited[maxidx] = true;
				if(count[maxidx] > 0) {
					last = maxidx;
					if(maxidx > 0 && deg[maxidx - 1] > 0) {
						deg[maxidx - 1]--;
					}
					if(maxidx < 25 && deg[maxidx + 1] > 0) {
						deg[maxidx + 1]--;
					}
				}
			}
		}
		if(answer) {
			for(int i = 0; i < 26; i++) {
				for(int j = 0; j < count[letter[i]]; j++) {
					cout << (char) ('a' + letter[i]);
				}
			}
			cout << endl;
		}
	}
}