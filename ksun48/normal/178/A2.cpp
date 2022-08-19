#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int stuff[n+1];
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
    for(int i = 1; i < n; i++){
        int total = 0;
        for(int j = 1; j <= n; j++){
            int k = j;
            int count = 0;
            while(k <= i){
                k = next[k];
                count++;
            }
            total += count*stuff[j];
        }
        cout << total << endl;
    }
    return 0;
}