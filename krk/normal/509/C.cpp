#include <cstdio>
#include <vector>
#include <string>
using namespace std;

const int Maxn = 305;

int n;
int b[Maxn];
string s[Maxn];
vector <int> sum;

bool Pos(int lft, int got) { return 0 <= got && got <= lft * 9; }

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	s[0] = "0";
	for (int i = 1; i <= n; i++) {
		sum.resize(s[i - 1].length());
		sum[0] = 0;
		for (int j = 1; j < s[i - 1].length(); j++)
			sum[j] = sum[j - 1] + (s[i - 1][j - 1] - '0');
		bool fnd = false;
		for (int j = s[i - 1].length() - 1; j >= 0 && !fnd; j--)
			if (sum[j] <= b[i]) {
				int to = min(b[i] - sum[j], 9);
				for (int k = s[i - 1][j] - '0' + 1; k <= to && !fnd; k++)
					if (Pos(s[i - 1].length() - 1 - j, b[i] - sum[j] - k)) {
						s[i] = s[i - 1];
						s[i][j] = k + '0'; b[i] -= (sum[j] + k);
						for (int z = j + 1; z < s[i].length(); z++) {
							int tk = max(0, int(b[i] - (s[i].length() - 1 - z) * 9));
							s[i][z] = '0' + tk; b[i] -= tk;
						}
						fnd = true;
					}
			}
		if (!fnd) {
			int gt = s[i - 1].length();
			while (max(b[i] - 9 * gt, 0) > 9) gt++;
			int fst = max(1, b[i] - 9 * gt);
			s[i].resize(gt + 1);
			s[i][0] = '0' + fst; b[i] -= fst;
			for (int z = 1; z < s[i].length(); z++) {
				int tk = max(0, int(b[i] - (s[i].length() - 1 - z) * 9));
				s[i][z] = '0' + tk; b[i] -= tk;
			}
		}
		printf("%s\n", s[i].c_str());
	}
	return 0;
}