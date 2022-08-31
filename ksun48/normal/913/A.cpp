#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    LL n, m;
    cin >> n >> m;
    if(n <= 40){
        cout << (m % (1LL << n)) << endl; 
    } else {
        cout << m << endl;
    }
}