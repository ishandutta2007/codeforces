#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    char b[n];
    cin >> b;
    if(k == 2){
        int aba = 0;
        int bab = 0;
        for(int i = 0; i < n; i++){
            if(b[i] == 'A'+i%2){
                bab++;
            } else {
                aba++;
            }
        }
        if(aba <= bab){
            cout << aba << endl;
            for(int i = 0; i < n; i++){
                if(i%2) cout << 'B';
                else cout << 'A';
            }
        } else {
            cout << bab << endl;
                for(int i = 0; i < n; i++){
                if(i%2) cout << 'A';
                else cout << 'B';
            }
        }
        cout << endl;
        return 0;
    }

    int ans = 0;
    for(int i = 1; i < n; i++){
        if(b[i] == b[i-1]){
            ans++;
            for(int j = 0; j < k; j++){
                if(j+'A' != b[i-1] && j+'A' != b[i+1]){
                    b[i] = j+'A';
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    cout << b << endl;
return 0;
}