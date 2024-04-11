#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	string a;
	cin >> n >> a;
	int c = 0;
	for(int i = 0; i < n-1; i++) if(a[i] == a[i+1]) c++;
	cout << n - max(c-2,0) << endl;
}