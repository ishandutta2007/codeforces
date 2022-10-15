#include <iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>

using namespace std;

long long f(long long n){
    return (n < 2)? 1: f(n - 1) * n;
}

int main() {
    long long a, b;
    cin >> a >> b;
    long long min = a;
    if (min > b) min = b;
    cout << f(min) << endl;
    return 0;
}