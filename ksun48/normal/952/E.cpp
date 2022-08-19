#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ns = 0;
    int nh = 0;
    for(int i = 0; i < n; i++){
        string a, b;
        cin >> a >> b;
        if(b == "soft"){
            ns++;
        } else {
            nh++;
        }
    }
    int k = 0;
    while(k*k < (ns + nh) || (k*k+1)/2 < max(ns, nh)){
        k++;
    }
    cout << k << endl;
}