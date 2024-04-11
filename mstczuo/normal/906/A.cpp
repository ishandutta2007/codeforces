# include <bits/stdc++.h>
using namespace std;

char buff[100010];

int calc() {
	scanf("%s", buff);
	int mask = 0;
	int len = strlen(buff);
	for(int i = 0; i < len; ++i) 
		mask |= 1 << (buff[i] - 'a');
	return mask;
}

int main() {
	int n;
	scanf("%d", &n);
	int mask = (1 << 26) - 1;
	bool flag = false;
	int cnt = 0;
	for(int i = 0; i < n; ++i) {
		scanf("%s", buff);
		char op = buff[0];
		if(!flag) {
			if(op == '!') {
				mask &= calc();
			} else if(op == '.') {
				mask &= ~calc();
			} else {
				mask &= ~calc();
			}
			if (mask == (mask & -mask)) flag = true;
		} else {
			if(op == '!') {
				if(mask & calc()) cnt++;
			} else if(op == '.') {
				calc();
			} else {
				if(calc() != mask) cnt++;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}