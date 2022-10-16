#include <cstdio>
#include <iostream>
#include <bitset>
using namespace std;
const int N = 5210;
bitset<N> a[N];
int n; 
//
int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j += 4){
            char x; cin >> x;
            if(x == '1') a[i][j + 3] = 1;
            else if(x == '2') a[i][j + 2] = 1;
            else if(x == '3') a[i][j + 2] = a[i][j + 3] = 1;
            else if(x == '4') a[i][j + 1] = 1;
            else if(x == '5') a[i][j + 1] = a[i][j + 3] = 1;
            else if(x == '6') a[i][j + 2] = a[i][j + 3] = 1;
            else if(x == '7') a[i][j + 1] = a[i][j + 2] = a[i][j + 3] = 1;
            else if(x == '8') a[i][j] = 1;
            else if(x == '9') a[i][j] = a[i][j + 3] = 1;
            else if(x == 'A') a[i][j] = a[i][j + 2] = 1;
            else if(x == 'B') a[i][j] = a[i][j + 2] = a[i][j + 3] = 1;
            else if(x == 'C') a[i][j] = a[i][j + 1] = 1;
            else if(x == 'D') a[i][j] = a[i][j + 1] = a[i][j + 3] = 1;
            else if(x == 'E') a[i][j] = a[i][j + 1] = a[i][j + 2] = 1;
            else if(x == 'F') a[i][j] = a[i][j + 1] = a[i][j + 2] = a[i][j + 3] = 1;
        }
    }
    for(int x = n; x >= 2; x--){
        if(n % x) continue;
        bool ep = true;
        for(int i = 1; i <= n; i += x){
            for(int j = i + 1; j < i + x; j++){
                ep = ep && (a[j] == a[i]);
                if(!ep) break;
            }
            if(!ep) break;
            for(int j = 1; j <= n; j += x){
                for(int k = j + 1; k < j + x; k++){
                    ep = ep && (a[i][k] == a[i][k - 1]);
                    if(!ep) break;
                }
                if(!ep) break;
            }
            if(!ep) break;
        }
        if(ep) { cout << x; return 0; }
    }
    cout << 1;
    return 0;
}