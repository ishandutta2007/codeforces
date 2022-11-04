#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m, i=0, x, y;
    cin >> n >> m;
    while(n--){
        for(int j = 0; j < m; j++){
            cin >> x >> y;
            if ( x > 0|| y>0 )
                i++;
        }
    }
    cout << i << endl;
}