#include<iostream>

using namespace std;


int main(){
    int n, m;
    cin >> n >> m;
    int b = 0;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++){
        int k;
        cin >> k;
        if(k == 1){
            int v, x;
            cin >> v >> x;
            a[v-1] = x-b;
        } else if(k == 2){
            int y;
            cin >> y;
            b += y;
        } else {
            int q;
            cin >> q;
            cout << a[q-1]+b << endl;
        }
    }
    

}