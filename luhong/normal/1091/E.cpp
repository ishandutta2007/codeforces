#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define MN 501000

long long s1[MN], s2[MN];
int cnt[MN];
int n;
int a[MN], d[MN];

bool cmp(int a, int b) {return a > b;}

int check(int x)
{
	memset(cnt, 0, sizeof(cnt));
	
	for(int i = 1; i < n; i++) d[i] = a[i];
	d[n] = x;
	for(int i = n; i > 1; i--)
	{
		if(d[i] > d[i - 1]) std::swap(d[i], d[i - 1]);
	}
	
	for(int i = 1; i <= n; i++) s1[i] = s1[i - 1] + d[i];
	
	int sum = 0;
	
	for(int i = n; i >= 1; i--)
	{
		s2[i] = s2[i + 1] + std::min(d[i], i - 1);
		sum += cnt[i];
		s2[i] -= sum;
		cnt[std::min(d[i], i - 1)]++;
	}
	
	for(int i = 1; i <= n; i++)
	{
		if(s1[i] > 1ll * i * (i - 1) + s2[i + 1]) 
			return d[i] > x ? 1 : -1;  
	}
	
	return 0;
}

int main()
{
	long long sum = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), sum += a[i];
	std::sort(a + 1, a + n + 1, cmp);
	
	n++;
	int ans1, ans2;
	int l = sum & 1 ? 1 : 0, r = n / 2 + 2;
	while(l < r)
	{
		int mid = l + r >> 1;
		int ans = check(mid * 2 - (sum & 1));
		if(ans == 0 || ans == -1) r = mid;
		else l = mid + 1; 
	}
	
	if(check(2 * r - (sum & 1)) != 0) return 0 * puts("-1");
	else ans1 = 2 * r - (sum & 1);
	
	l = sum & 1 ? 1 : 0, r = n / 2 + 2;
	while(l < r)
	{
		int mid = l + r >> 1;
		int ans = check(mid * 2 - (sum & 1));
		if(ans == 0 || ans == 1) l = mid + 1;
		else r = mid; 
	}
	
	l--;
	if((sum & 1) && l == 0) return 0 * puts("-1");
	if(!(sum & 1) && l == -1) return 0 * puts("-1");
	
	if(check(2 * l - (sum & 1)) != 0) return 0 * puts("-1");
	else ans2 = 2 * l - (sum & 1);
	
	for(int i = ans1; i <= ans2; i += 2) printf("%d ", i);
	return 0; 
}

//di 
//(1 <= k <= n) di (1 <= i <= k) <= k * (k-1) + min(di, k) (k + 1 <= i <= n) 
// 
//ErdosGallai theorem O(n)
//BobBob