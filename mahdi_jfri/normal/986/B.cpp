#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define lb(a) ((a)&(-(a)))

const int maxn = 1e6 + 20;

int fen[maxn] , a[maxn];

void add(int p , int val)
{
	for(p++; p < maxn; p += lb(p))
		fen[p] += val;
}

int get(int p)
{
	int res = 0;
	for(p++; p > 0; p -= lb(p))
		res += fen[p];

	return res;
}

int main()
{
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		a[i]--;
	}

	int t = 0;
	for(int i = n - 1; i >= 0; i--)
	{
		t += get(a[i]);
		add(a[i] , 1);
	}

	if(n % 2)
	{
		if(t % 2)
			cout << "Petr" << endl;
		else
			cout << "Um_nik" << endl;
	}
	else
	{
		if(t % 2)
			cout << "Um_nik" << endl;
		else
			cout << "Petr" << endl;
	}

}