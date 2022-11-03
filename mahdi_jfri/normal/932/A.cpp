#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int main()
{
	string a;
	cin >> a;
	string tmp = a;
	reverse(a.begin() , a.end());
	cout << tmp + a << endl;
}