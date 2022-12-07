#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
char s[200001], out[20];
int len[200001];
int ans1[2000001], ans2[2000001];
vector<int> v[2000001];
int digit[6];
bool solve(int n, int i, int sum)
{
	if (!i){
		if (ans1[sum] >= 10)return false;
		ans2[n] = sum;
		return true;
	}
	for (int j = 1, k = 10; k <= i * 10; j++, k *= 10){
		if (solve(n, i / k, sum + i%k)){
			v[n].push_back(j);
			return true;
		}
	}
	return false;
}
int main()
{
	int n;
	for (int i = 1; i <= 2000000; i++){
		int j = 0;
		for (; digit[j] == 9; digit[j++] = 0);
		digit[j]++;
		int sum = 0;
		for (int j = 0; j < 6; j++)sum += digit[j];
		ans1[i] = sum;
	}
	for (int i = 1; i <= 2000000; i++){
		v[i].reserve(7);
		solve(i, i, 0);
	}
	scanf("%d%s", &n, s);
	int sum;
	while (1){
		if (n > 10){
			int t = rand() % min(n / 2, 500);
			for (int i = 0; i < t; i++)
				len[i] = 2;
			for (int i = 2 * t; i < n; i++)
				len[i - t] = 1;
			random_shuffle(len, len + n - t);
		}
		else for (int i = 0; i < n; i++)
			len[i] = 1;
		sum = 0;
		for (int i = 0, j = 0; j < n; j += len[i++])
			sum += len[i] == 1 ? s[j] - '0' : (s[j] - '0') * 10 + s[j + 1] - '0';
		if (!v[sum].empty())break;
	}
	for (int i = 0, j = 0; j < n; j += len[i++]){
		if (i)putchar('+');
		putchar(s[j]);
		if (len[i]>1)putchar(s[j + 1]);
	}
	putchar('\n');
	sprintf(out, "%d", sum);
	int j = 0;
	for (int i : v[sum]){
		if (j)putchar('+');
		for (int k = 0; k < i; k++)
			putchar(out[j + k]);
		j += i;
	}
	putchar('\n');
	sum = ans2[sum];
	sprintf(out, "%d", sum);
	for (int i = 0; out[i]; i++){
		if (i)putchar('+');
		putchar(out[i]);
	}
	putchar('\n');
}