#include <iostream>
using namespace std;

#define ll long long
#define N 100000

ll a[N], A[N], B[N], C[N];
int n;

ll even(ll i)
{
	return (i - i % 2);
}
ll odd(ll i)
{
	if(i % 2) return i;
	return i - 1;
}

int main()
{
	cin >> n;
	for(int i = 0; i < n - 1; i ++)
		cin >> a[i];

	A[0] = 0;
	for(int i = 1; i < n; i ++)
		if( even(a[i - 1]) == 0 ) A[i] = 0;
		else A[i] = even( a[i - 1] ) + A[i - 1];

	B[0] = 0;
	for(int i = 1; i < n; i ++)
		if( odd( a[i - 1] )==0 ) B[i] = 0;
		else B[i] = odd( a[i - 1] ) + max( A[i - 1], B[i - 1] );
	C[0] = 0;
	for(int i = 1; i < n; i ++)
		if( even( a[i - 1] )==0 ) C[i] = 0;
		else C[i] = even( a[i - 1] ) + max( B[i - 1], C[i - 1] );
	ll Ans = 0;
	for(int i = 0; i < n; i ++)
	{
		if( A[i] > Ans ) Ans = A[i];
		if( B[i] > Ans ) Ans = B[i];
		if( C[i] > Ans ) Ans = C[i];
	}
	cout << Ans << endl;
}