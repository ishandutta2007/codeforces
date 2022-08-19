#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL n, k;
	cin >> n >> k;
	LL c = max(n-2*k,0LL);
	LL a = n*(n-1)/2-c*(c-1)/2;
	cout << a << endl;
}