#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int a, b, c, d, n;
	scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
	int e = max(a,d) + max(b,c);
	int f = min(a,d) + min(b,c);
	if(1-f>n-e){
		cout << 0 << endl;
		return 0;
	}
	LL r = (n-e)-(1-f)+1;
	r = r*((LL)n);
	cout << r << endl;
}