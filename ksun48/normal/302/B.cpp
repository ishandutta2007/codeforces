#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int song[n];
    int a, b;
    cin >> a >> b;
    song[0] = a*b;
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        song[i] = song[i-1]+a*b;
    }
    int k = 0;
    for(int i = 0; i < m; i++){
        int c;
        cin >> c;
        while(c > song[k]){
            k++;
        }
        cout << k + 1 << endl;
    }
    return 0;
}