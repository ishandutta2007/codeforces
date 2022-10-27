#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    for(cin >> T; T -- ;){
        int n, a, b, c;
        cin >> a >> b >> c >> n;
        int sum = a + b + c + n;
        if(sum % 3){
            cout << "NO\n";
            continue;
        }
        int A = sum / 3 - a;
        int B = sum / 3 - b;
        int C = sum / 3 - c;
        if(A < 0 || B < 0 || C < 0)
            cout << "NO\n";
        else cout << "YES\n";
    }

}
/*
    Good Luck
        -Lucina
*/