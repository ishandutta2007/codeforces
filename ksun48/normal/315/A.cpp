#include<iostream>

using namespace std;


int main(){
    int n;
    cin >> n;
    int a[n], b[n];
    int c[n];
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        c[i] = 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i] == b[j] && i != j){
                c[i] = 1;
            }
        }
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(c[i] == 0) sum++;
    }
    cout << sum << endl;

}