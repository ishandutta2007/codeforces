#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    if(d && ((!c) || (b && !a) || b * d * f > a * c * e)){
        cout << "Ron" << '\n';
    } else {
        cout << "Hermione" << '\n';
    }
}