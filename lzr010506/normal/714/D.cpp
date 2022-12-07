#include <bits/stdc++.h>
using namespace std;
int n;
int check(int x1, int y1, int x2, int y2)
{
	printf("? %d %d %d %d\n", x1, y1, x2, y2);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}
vector<int> ans;
void reduce(int x1, int y1, int x2, int y2)
{
	int l = x1, r = x2;
	while(l < r)
	{
		int mid = (l + r) >> 1;
		if(check(x1, y1, mid, y2) == 1) r = mid;
		else l = mid + 1;
	}
	x2 = l;
	l = x1, r = x2;
	while (l < r) 
	{
		int mid = (l + r + 1) >> 1;
		if(check(mid, y1, x2, y2) == 1)  l = mid; 
		else r = mid - 1;
	}
	x1 = l;
	l = y1, r = y2;
	while (l < r) 
	{
		int mid = (l + r) >> 1;
		if(check(x1, y1, x2, mid) == 1) r = mid; else l = mid + 1;
	}
	y2 = l;
	l = y1, r = y2;
	while (l < r) 
	{
		int mid = (l + r + 1) >> 1;
		if(check(x1, mid, x2, y2) == 1) l = mid; else r = mid - 1;
	}
	y1 = l;
	ans.push_back(x1);
	ans.push_back(y1);
	ans.push_back(x2);
	ans.push_back(y2);
}

void Out() 
{
	putchar('!');
	for (int i = 0; i < ans.size(); ++i) printf(" %d", ans[i]);
	putchar('\n');
	fflush(stdout);
	exit(0);
}

void findX() 
{
	int l = 1, r = n;
	while (l < r) 
	{
		int mid = (l + r) >> 1;
		int p = check(1, 1, mid, n);
		if (p) r = mid; else l = mid + 1;
	}
	if (check(1, 1, l, n) == 1 && check(l + 1, 1, n, n) == 1) 
	{
		ans.clear();
		reduce(1, 1, l, n);
		reduce(l + 1, 1, n, n);
		Out();
	}
}

void findY() 
{
	int l = 1, r = n;
	while (l < r) 
	{
		int mid = (l + r) >> 1;
		int p = check(1, 1, n, mid);
		if (p) r = mid; else l = mid + 1;
	}
	ans.clear();
	reduce(1, 1, n, l);
	reduce(1, l + 1, n, n);
	Out();
}

int main() 
{
	scanf("%d", &n);
	findX();
	findY();
	return 0;
}