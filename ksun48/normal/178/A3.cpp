#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long stuff[n+1];
    for(int i = 1; i <= n; i++){
        cin >> stuff[i];
    }
    int next[n];
    for(int i = 1; i < n; i++){
        next[i] = i + int(pow(2, int(log(n-i+.01)/log(2))));
    }   
    for(int i = 1; i < n; i++){
        //cout << i << " " << next[i] << endl;
    }
    long long total = 0;
    for(int i = 1; i < n; i++){
        stuff[next[i]] += stuff[i];
        total += stuff[i];
        stuff[i] = 0;
        cout << total << endl;
    }
    return 0;
}