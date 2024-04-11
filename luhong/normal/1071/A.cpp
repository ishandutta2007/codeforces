#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int a, b;
bool used[101000]; int cnt = 0;

bool check(int x)
{
	int m = b;
	int s = 0;
	for(int i = x; i >= 1; i--)
	{
		if(m >= i) m -= i, s += i;
	}
	long long sum = 1ll * (1 + x) * x / 2;
	if(sum - s <= a) return 1;
	else return 0; 
}

void get_ans(int x)
{
	int m = a;
	for(int i = x; i >= 1; i--)
	{
		if(m >= i) m -= i, used[i] = 1, cnt++;
	}
	printf("%d\n", cnt);
	for(int i = 1; i <= x; i++) if(used[i]) printf("%d ", i); puts("");
	printf("%d\n", x - cnt);
	for(int i = 1; i <= x; i++) if(!used[i]) printf("%d ", i);
}
int main()
{
	scanf("%d%d", &a, &b);
	int l = 1, r = 100001;
	while(l < r)
	{
		int mid = l + r >> 1;
		if(check(mid)) l = mid + 1;
		else r = mid;
	}
	get_ans(l - 1);
	return 0;
}