#include<bits/stdc++.h>
#define int long long
#define double long double
#define pb push_back
#define mp make_pair
#define sp ' '
#define endl '\n'
#define fi first
#define se second
using namespace std;

const int mod = 1e9+7;
const int N = 205;
const double pi = acos(-1);//dai cathay

signed main()
{
	int a,b,x;
	cin >> x >> a >> b;
	if(a > b) swap(a,b);
	int ans = 1;
	while(a + 1 != b || a%2==0) {
	    a = (a+1)/2;
	    b = (b+1)/2;
	    ++ans;
	}
int tem = 1 << ans;
if(tem == x) cout <<"Final!";
else cout << ans;
}