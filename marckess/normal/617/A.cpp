#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int i = 0;
    while(n >= 5){
        n -= 5;
        i++;
    }
    while(n >= 4){
        n -= 4;
        i++;
    }
    while(n >= 3){
        n -= 3;
        i++;
    }
    while(n >= 2){
        n -= 2;
        i++;
    }
    while(n >= 1){
        n -= 1;
        i++;
    }
    cout << i;
}