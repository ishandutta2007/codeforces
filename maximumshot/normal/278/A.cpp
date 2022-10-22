#include <iostream>
#include <cmath>

using namespace std;

typedef long long LL;
typedef unsigned long long ull;
const int inf = 1000 * 1000 * 1000;
const LL inf64 = LL(inf) * inf;

void qs(LL *arr,LL *index,LL left,LL right)
{
	LL l = left,r = right,mid = arr[(l+r)/2];

	do{
		while(arr[l] < mid)l++;
		while(arr[r] > mid)r--;

	if(l <= r)
	{
		if(l < r)
		{
			swap(arr[l],arr[r]);
			swap(index[l],index[r]);
		}
	l++;r--;
	}
	}while(l<=r);

	if(l < right)qs(arr,index,l,right);
	if(r > left) qs(arr,index, left,r);
}

bool solve()
{
	int n,S[100],min(0),i,j,tmp(0);

	cin >> n;

	for(int i(0);i < n;i++)cin >> S[i];

	cin >> i >> j;i--;j--;

	if(i > j)swap(i,j);

	for(int q(i);q < j;q++)
	{
		min += S[q];
	}
	
	for(int q(j);q < n;q++)tmp += S[q];
	for(int q(0);q < i;q++)tmp += S[q];

	if(min < tmp) cout << min;
	else cout << tmp;

	return true;
}

int main(int argc,char** argv)
{
	setlocale(LC_ALL,"Russian");
	solve();

	return 0;
}