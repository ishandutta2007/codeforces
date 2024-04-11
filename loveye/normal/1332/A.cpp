#include<bits/stdc++.h>
using namespace std;
int a,b,a1,b1,a2,b2,x,y,c,d;
inline int inmap(int x,int y) {
	return a1 <= x && x <= a2 && b1 <= y && y <= b2;
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> a >> b >> c >> d;
		cin >> x >> y >> a1 >> b1 >> a2 >> b2;
		if((a1 == a2 && (a || b)) || (b1 == b2 && (c || d))) puts("NO");
		else puts(inmap(x,y) && inmap(x-a+b,y-c+d) ? "YES" : "NO");
	}
	return 0;
}