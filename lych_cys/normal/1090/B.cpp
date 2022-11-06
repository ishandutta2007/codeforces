#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#define MAXN 100000
int state = 0;
std::string buf;
int son[MAXN][26], id[MAXN], cnt = 1, n = 0, m = 0;
std::vector<std::string> ref;
int rid[MAXN], pid[MAXN], ok = 1;
int main() {
	while (std::getline(std::cin, buf)) {
		if (state == 0) {
			if (buf == "\\begin{thebibliography}{99}") {
				state = 1;
				continue;
			}
			for (int i = 0; i < (int)buf.length(); i++) {
				if (buf[i] == '\\') {
					i += 6;
					int p = 1;
					for (; buf[i] != '}'; i++) {
						int &nx = son[p][buf[i] - 'a'];
						if (!nx) nx = ++cnt;
						p = nx;
					}
					id[p] = ++n;
				}
			}
		} else {
			if (buf == "\\end{thebibliography}") {
				break;
			}
			ref.push_back(buf);
			++m;
			for (int i = 0; i < (int)buf.length(); i++) {
				if (buf[i] == '\\') {
					i += 9;
					int p = 1;
					for (; buf[i] != '}'; i++) p = son[p][buf[i] - 'a'];
					rid[m] = id[p];
					break;
				}
			}
			ok &= rid[m] == m;
		}
	}
	if (ok) return puts("Correct"), 0;
	for (int i = 1; i <= m; i++) pid[rid[i]] = i;
	puts("Incorrect");
	puts("\\begin{thebibliography}{99}");
	for (int i = 1; i <= m; i++) puts(ref[pid[i] - 1].c_str());
	puts("\\end{thebibliography}");
	return 0;
}