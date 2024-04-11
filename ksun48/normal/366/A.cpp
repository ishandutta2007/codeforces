#include<iostream>
using namespace std;
typedef long long LL;
int n;
int yes = 0;
void k(int i, int a, int b){
	if(yes) return;
	if(a+b <= n){
		yes = 1;
		cout << i << " " << a << " " << n-a << endl;
	}
	return;
}
int main(){
	cin >> n;
	for(int i = 1; i <= 4; i++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		k(i,a,c);
		k(i,a,d);
		k(i,b,c);
		k(i,b,d);
	}
	if(yes) return 0;
	cout << -1 << endl;

}