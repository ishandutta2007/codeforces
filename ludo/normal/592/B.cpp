#include<cassert>
#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    while(true) {
        long long n;
        cin >> n;
        if(!cin) {
            break;
        }
        long long ans = n * n - 4 * n + 4;
        cout << ans << endl;
    }
    return 0;
}