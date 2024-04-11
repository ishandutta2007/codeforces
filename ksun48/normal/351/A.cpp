#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    n = 2*n;
    int a[n];
    char k[10];
    int sum = 0;
    int nonzero = 0;
    for(int i = 0; i < n; i++){
        cin >> k;
        int j = 0;
        while(k[j]!='.') j++;
        a[i] = (k[j+1]-'0')*100+(k[j+2]-'0')*10+(k[j+3]-'0');
        sum += a[i];
        if(a[i] != 0) nonzero++;
    }
    double minz = 1000000.0;
    for(int i = max(nonzero-n/2,0); i <= min(nonzero, n/2); i++){
        minz = min(minz, abs((sum-i*1000.0)/1000.0));
    }
    printf("%.3lf\n", minz);
    return 0;
}