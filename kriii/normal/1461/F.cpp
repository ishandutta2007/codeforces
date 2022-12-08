#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, a[100100]; char s[6], r[100100];

int main()
{
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) scanf ("%d", &a[i]);
	scanf ("%s", s);

	int l = 0; while (s[l]) l++;

	if (l == 1){
		for (int i = 0; i < n; i++) r[i] = s[0];
	}
	else{
		bool mul = false;
		bool plus = false;
		bool minus = false;
		for (int i = 0; i < l; i++){
			if (s[i] == '*') mul = true;
			if (s[i] == '+') plus = true;
			if (s[i] == '-') minus = true;
		}

		if (!mul){
			for (int i = 0; i < n; i++) r[i] = '+';
		}
		else if (plus){
			for (int i = 0; i < n; i++) r[i] = '*';

			for (int i = 0; i < n; i++) if (a[i] == 0) r[i] = r[i + 1] = '+';
			for (int i = 0; i < n; i++) if (a[i]){
				int j = i;
				while (j < n && a[j]) j++;

				long long v = 1;
				int th = (j - i) * 4;
				for (int k = i; k < j; k++){
					v *= a[k];
					if (v > th) break;
				}
				if (v <= th){
					for (int k = i + 1; k < j; k++) r[k] = '+';
					struct intv{ int m, l, r; };
					vector<intv> seg;
					int m = 1, s = -1;
					for (int k = i; k < j; k++){
						if (a[k] > 1){
							if (s == -1) s = k;
							m *= a[k];
						}
						else{
							if (s != -1) seg.push_back({ m, s, k });
							m = 1; s = -1;
						}
					}
					if (s != -1) seg.push_back({ m, s, j });

					int z = (int)seg.size() - 1;
					for (auto s : seg) for (int k = s.l + 1; k < s.r; k++) r[k] = '*';
					if (z >= 1){
						int mx = -1, p = -1;
						for (int b = 0; b < (1 << z); b++){
							int m = seg[0].m, s = 0;
							for (int i = 0; i < z; i++){
								if (b & (1 << i)) m *= seg[i + 1].m;
								else{
									s += m;
									s += seg[i + 1].l - seg[i].r;
									m = seg[i + 1].m;
								}
							}
							s += m;
							if (mx < s){
								mx = s;
								p = b;
							}
						}

						for (int i = 0; i < z; i++) if (p & (1 << i)){
							for (int k = seg[i].r; k <= seg[i + 1].l; k++) r[k] = '*';
						}
					}
				}
				else{
					for (int k = i; k < j; k++){
						if (a[k] == 1) r[k + 1] = '+';
						else break;
					}
					for (int k = j - 1; k >= i; k--){
						if (a[k] == 1) r[k] = '+';
						else break;
					}
				}
				i = j;
			}
		}
		else{
			for (int i = 0; i < n; i++) r[i] = '*';
			for (int i = 1; i < n; i++) if (!a[i]){
				r[i] = '-';
				break;
			}
		}
	}

	for (int i = 0; i < n; i++){
		if (i) putchar(r[i]);
		printf ("%d", a[i]);
	}

	return 0;
}