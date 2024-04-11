#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;

int n, b[MAXN], tot, totalsum;
int a[MAXN], k, cnt, rcnt;
bool rm[MAXN];
char str[MAXN];
vector <int> position;

int Rand(){return (rand() << 15) ^ rand();}
bool ok(int x) {
	int s = 0;
	while (x) {
		s += x % 10; x /= 10;
	}
	return (s < 10);
}
bool isValid(int x) {
	//printf("valid: %d\n", x);
	tot = 0;
	while (x) {
		b[++tot] = x % 10; x /= 10;
	}
	reverse(b + 1, b + tot + 1);
	for (int sta = 0; sta < (1 << (tot - 1)); ++sta) {
		int tmp = 0, sum = 0;
		for (int i = 1; i <= tot; ++i) {
			tmp = tmp * 10 + b[i];
			if (i == tot || (sta & (1 << (i - 1)))) {
				sum += tmp; tmp = 0;
			}
		}
		if (ok(sum)) {
			for(int i = 0; i < int(position.size()); ++ i)
		rm[position[i]] = true;
	for(int i = 1; i < n; ++ i){
		putchar(str[i]);
		if(!rm[i]) putchar('+');
	} putchar(str[n]);
	putchar('\n');
			for (int i = 1; i <= tot; ++i) {
				printf("%d", b[i]);
				if (sta & (1 << (i - 1)))
					putchar('+');
			}
			puts("");
			tot = 0;
			//printf("num: %d\n", sum);
			while(sum) b[++ tot] = sum % 10, sum /= 10;
			reverse(b + 1, b + 1 + tot);
			for(int i = 1; i < tot; ++ i)
				putchar(b[i] + '0'), putchar('+');
			putchar(b[tot] + '0'); puts("");
			return 1;
		}
	}
	return 0;
}
bool check(){
	int i, sum = totalsum, cur; rcnt = rand() % (cnt + 1);
	for(i = 1; i <= rcnt; ++ i){
		position.push_back(Rand() % (n - 1) + 1);
		if(rm[position.back()] || rm[position.back() - 1] || rm[position.back() + 1]){
			position.pop_back(); continue;
		} rm[position.back()] = true;
		//printf("rm %d %d\n", str[position.back()] - '0', str[position.back() + 1] - '0');
		sum -= (str[position.back()] - '0') + (str[position.back() + 1] - '0');
		sum += (str[position.back()] - '0') * 10 + (str[position.back() + 1] - '0');
	}
	for(i = 0; i < int(position.size()); ++ i)
		rm[position[i]] = false;
	return isValid(sum);
}
bool spcheck(){
	int i, sum, cur; rcnt = 0;
	for(i = 1; i <= rcnt; ++ i){
		position.push_back(Rand() % (n - 1) + 1);
		rm[position.back()] = true;
	}
	for(i = 1, sum = cur = 0; i <= n; ++ i){
		cur = cur * 10 + str[i] - '0';
		if((!rm[i]) || i == n) sum += cur, cur = 0;
	}
	for(i = 0; i < int(position.size()); ++ i)
		rm[position[i]] = false;
	return isValid(sum);
}
int main(){
	srand(time(NULL));
	scanf("%d%s", &n, str + 1);
	if(n <= 30) cnt = min(n - 1, 3);
	else cnt = min(n / 10, 20);
	for(int i = 1; i <= n; ++ i)
		totalsum += str[i] - '0';
	if(spcheck()) return 0;
	while(!check()) position.clear();
	return 0;
}