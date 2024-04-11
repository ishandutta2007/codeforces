#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define e1 first
#define e2 second
#define pb push_back
#define milion 1000100
#define tysiac 1010
#define dwa_tysiace 2010
#define sto_tysiecy 100100
typedef long long int ll;
typedef unsigned long long int ull;
typedef unsigned int ui;
typedef pair <int, int> BONG;
typedef pair <BONG, BONG> LONG;
const int inf = 1e9+9;
const int mod = 1e9+7;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int n,m,a , b, d;
int t[milion];
int A[tysiac], B[tysiac];

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> a >> b;
	cin >> n >> d;
	if (a > b) swap(a,b);
	A[1] = a;
	B[n] = b;
	for (int i=2; i<=n; ++i) A[i] = A[i-1] + d;
	for (int i=n-1; i>0; --i) B[i] = B[i+1] + d;
	ll sum = 0;
	int poz = 0;
	for (int i=1; i<=n; ++i) 
	  if (abs(A[i] - B[i + 1]) <= d && poz == 0) poz = i;
	for (int i=1; i<=poz; ++i) sum += A[i];
	for (int j=poz+1; j<=n; ++j) sum+= B[j];
	cout << sum << endl;
	
	
}