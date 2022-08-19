#include<iostream>
using namespace std;
typedef long long LL;

int main(){
	int a; int b;
	cin >> a >> b;
	int used = a;
	int ans = a;
	while(used >= b){
		ans += used/b;
		used = (used % b) + used/b;
	}
	cout << ans << endl;
}