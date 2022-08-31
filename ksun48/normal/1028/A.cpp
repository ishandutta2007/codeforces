#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main(){
    LL n, m;
    cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    int nb = 0;
    int sumx = 0;
    int sumy = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i][j] == 'B'){
                nb++;
                sumx += i;
                sumy += j;
            }
        }
    }
    sumx /= nb;
    sumy /= nb;
    cout << sumx + 1 << " " << sumy + 1 << endl;
}