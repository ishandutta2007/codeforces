#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int Maxn = 100005;
const int Maxl = 10;

int n;
char tmp[Maxl];
string num[Maxn];
string cur;
string lst[Maxn][Maxl];
bool pos[Maxn][Maxl];
string mn[Maxn][Maxl];

bool canMake()
{
	cur = "0";
	for (int i = 0; i < n; i++) {
		if (cur.length() > num[i].length()) return false;
		if (cur.length() < num[i].length()) {
			if (num[i][0] == '?') num[i][0] = '1';
			for (int j = 1; j < num[i].length(); j++)
				if (num[i][j] == '?') num[i][j] = '0';
			cur = num[i];
			continue;
		}
		pos[i][cur.length()] = false;
		mn[i][cur.length()] = "";
		for (int j = cur.length() - 1; j >= 0; j--) {
			if (num[i][j] == '?') {
				if (pos[i][j + 1]) {
					pos[i][j] = true;
					lst[i][j] = string(1, cur[j]) + lst[i][j + 1];
				} else if (cur[j] != '9') {
					pos[i][j] = true;
					lst[i][j] = string(1, cur[j] + 1) + mn[i][j + 1];
				} else pos[i][j] = false;
				mn[i][j] = string(1, (j? '0': '1')) + mn[i][j + 1];
			} else {
				if (cur[j] < num[i][j]) {
					pos[i][j] = true;
					lst[i][j] = string(1, num[i][j]) + mn[i][j + 1];
				} else if (cur[j] == num[i][j] && pos[i][j + 1]) {
					pos[i][j] = true;
					lst[i][j] = string(1, num[i][j]) + lst[i][j + 1];
				} else pos[i][j] = false;
				mn[i][j] = string(1, num[i][j]) + mn[i][j + 1];
			}
		}
		int j;
		for (j = 0; j < cur.length(); j++)
			if (num[i][j] == '?') 
				if (pos[i][j]) { num[i] = (j? num[i].substr(0, j): "") + lst[i][j]; break; }
				else return false;
			else if (cur[j] > num[i][j]) return false;
				 else if (cur[j] < num[i][j]) { num[i] = (j? num[i].substr(0, j): "") + mn[i][j]; break; }
		if (j >= cur.length()) return false;
		cur = num[i];
	}
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", tmp); num[i] = tmp;
	}
	if (canMake()) {
		printf("YES\n");
		for (int i = 0; i < n; i++)
			printf("%s\n", num[i].c_str());
	} else printf("NO\n");
	return 0;
}