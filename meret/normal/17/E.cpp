#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 2000001;
const int MD = 51123987;

int n;

int oddRadius[N + 1];
int evenRadius[N + 1];

char s[N + 1];

void calcOdd(int *t) {
        int r = 0;
        for (int i = 1; i <= n; ++i) {
                if (r + t[r] >= i)
                        t[i] = min(t[2 * r - i], r + t[r] - i);
                while (i + t[i] < n && i - t[i] > 1 && s[i - t[i] - 1] == s[i + t[i] + 1])
                        ++t[i];
                if (i + t[i] > r + t[r])
                        r = i;
        }
}

void calcEven(int *t) {
        int r = 0;
        for (int i = 1; i <= n; ++i) {
                if (r + t[r] >= i)
                        t[i] = min(t[2 * r - i], r + t[r] - i);
                while (i + t[i] < n && i - t[i] + 1 > 1 && s[i - t[i]] == s[i + t[i] + 1])
                        ++t[i];
                if (i + t[i] > r + t[r])
                        r = i;
        }
}

int subtract[N];

LL contained[N];

int main() {
	scanf("%d %s", &n, s + 1);
	calcOdd(oddRadius);
	calcEven(evenRadius);
	int count = 0;
	LL sum = 0;
	for (int i = n; i >= 1; --i) {
		sum -= count;
		count -= subtract[i];
		if (evenRadius[i] > 0) {
			++count;
			sum += evenRadius[i];
			++subtract[i - evenRadius[i]];
		}
		if (oddRadius[i + 1] > 0) {
			++count;
			sum += oddRadius[i + 1];
			++subtract[i - oddRadius[i + 1]];
		}
		contained[i] += sum;
	}
	memset(subtract, 0, sizeof(subtract));
	count = 0;
	sum = 0;
	LL res = 0;
	for (int i = 1; i <= n; ++i) {
		sum -= count;
		count -= subtract[i];
		if (evenRadius[i - 1] > 0) {
			++count;
			sum += evenRadius[i - 1];
			++subtract[i + evenRadius[i - 1]];
		}
		++count;
		sum += oddRadius[i] + 1;
		++subtract[i + oddRadius[i] + 1];
		contained[i] += sum;
		res = (res + count * (contained[i] % MD)) % MD;
		res = ((res - count * LL(count + 1) / 2) % MD + MD) % MD;
	}
	printf("%d\n", int(res));
}