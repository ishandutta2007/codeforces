#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int a, ta;
	int b, tb;
	cin >> a >> ta >> b >> tb;
	int ans = 0;
	string c;
	cin >> c;
	int d = 0;
	d += (c[0]-'0')*600;
	d += (c[1]-'0')*60;
	d += (c[3]-'0')*10;
	d += (c[4]-'0')*1;
	int q = 300;
	while(q < 1440){
		if(q+tb > d && q < d+ta){
			ans++;
		}
		q += b;
	}
	cout << ans << endl;
}