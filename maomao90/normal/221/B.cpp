#include <bits/stdc++.h>
using namespace std;

int x;
bool isUsed[10];
int ans;

int main() {
	scanf("%d", &x);
	string tempx = to_string(x);
	for (int i = 0; i < tempx.size(); i++) {
		isUsed[tempx[i] - '0'] = true;
	}
	if (x == 1) {
        printf("1\n");
        return 0;
	}
	for (int i = 1; i * i <= x; i++) {
        if (x % i != 0) continue;
		string tempi = to_string(i);
		bool correct = false;
		for (int j = 0; j < tempi.size(); j++) {
			if (isUsed[tempi[j] - '0']) correct = true;
		}
		if (correct) {
            ans++;
		}
		if (i * i == x) continue;
		tempi = to_string(x / i);
		correct = false;
		for (int j = 0; j < tempi.size(); j++) {
			if (isUsed[tempi[j] - '0']) correct = true;
		}
		if (correct) {
            ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}