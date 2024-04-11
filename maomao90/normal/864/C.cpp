#include <cstdio>

using namespace std;

int a, b, f, k;
int cur;
int ans;
bool atStart = true;

int main() {
	scanf("%d%d%d%d", &a, &b, &f, &k);
	cur = b;
	for (int i = 0; i < k - 1; i++) {
		if (atStart) {
            if (cur < f) {
                printf("-1\n");
                return 0;
            }
			if (cur < a + (a - f)) {
				ans++;
				cur = b - (a - f);
			} else {
				cur -= a;
			}
			if (cur < 0) {
                printf("-1\n");
                return 0;
			}
		} else {
		    if (cur < a - f) {
                printf("-1\n");
                return 0;
		    }
			if (cur < a + f) {
				ans++;
				cur = b - f;
			} else {
				cur -= a;
			}
			if (cur < 0) {
                printf("-1\n");
                return 0;
			}
		}
        atStart = !atStart;
	}
    if (atStart) {
        if (cur < f) {
            printf("-1\n");
            return 0;
        }
        if (cur < a) {
            ans++;
            cur = b - (a - f);
        } else {
            cur -= a;
        }
        if (cur < 0) {
            printf("-1\n");
            return 0;
        }
    } else {
        if (cur < a - f) {
            printf("-1\n");
            return 0;
		    }
        if (cur < a) {
            ans++;
            cur = b - f;
        } else {
            cur -= a;
        }
        if (cur < 0) {
            printf("-1\n");
            return 0;
        }
    }
	printf("%d\n", ans);
	return 0;
}