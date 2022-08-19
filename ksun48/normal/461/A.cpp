#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;

int main(){
	LL n;
	cin >> n;
	LL a[n];
	for(LL i = 0; i < n; i++) cin >> a[i];
	sort(a, a+n);
	LL answer = 0;
	for(LL i = 0; i < n; i++){
		answer += (i+2)*a[i];
	}
	answer -= a[n-1];
	cout << answer << endl;
}