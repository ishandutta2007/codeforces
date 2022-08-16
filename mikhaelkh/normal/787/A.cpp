#include <bits/stdc++.h>
using namespace std;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    int a, b, c, d;
    cin >> b >> a >> d >> c;
    if (a < c) a += (c-a) / b * b;
    if (c < a) c += (a-c) / d * d;
    for (int i=0; i<999999; ++i) {
    	if (a<c) a += b;
    	else if (a>c) c += d;
    	else {
    		cout << a << endl;
    		return 0;
    	}
    }
    cout << -1 << endl;
     

    
    return 0;
}