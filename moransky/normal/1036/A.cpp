#include <cstdio>
#include <iostream>
#include <cmath>
typedef long long LL;
using namespace std;
LL n, k;
int main(){
    cin >> n >> k;
    cout << ((k % n) ? k / n + 1 : k / n );
    return 0;
}