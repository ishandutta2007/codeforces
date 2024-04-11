#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int a, n, b;
	cin >> n >> a >> b;
	cout << ((a+b-1)%n+n)%n+1 << endl;
}