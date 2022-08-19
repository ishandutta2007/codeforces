#include <bits/stdc++.h>
using namespace std;
int main(){
using ld = long double;
cout << fixed << setprecision(10);
ld S;
ld a, b, c;
cin >> S >> a >> b >> c;
if(a < 1e-4 && b < 1e-4 && c < 1e-4){
cout << S << ' ' << 0 << ' ' << 0 << '\n';
} else {
S /= (a+b+c);
cout << (a*S) << " " << (b*S) << " " << (c*S) << '\n';
}
}