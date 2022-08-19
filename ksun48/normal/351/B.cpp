#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int k = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(a[i]>a[j]){
                k++;
            }
        }
    }
    if(k % 2 == 0){
    cout << 2*k << endl;
    } else {
    cout << 2*k-1 << endl;
    }
}