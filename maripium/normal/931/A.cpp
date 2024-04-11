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
const double pi = acos(-1);//xam

signed main()
{
	int a,b;
	cin >> a >> b;
	if(a < b) swap(a,b);
	if((a - b) % 2){
		int x = (a - b) / 2 + 1;
		cout << x * x << endl;
	}
	else {
		int x = (a - b) / 2;
		cout << x * x + x << endl; 
	}
}