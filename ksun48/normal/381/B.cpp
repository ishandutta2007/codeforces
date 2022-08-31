#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[8010];
    int scan1[n];
    for(int i = 0; i < 5944; i++) a[i] = 0;
    for(int i = 0; i < n; i++){
        cin >> scan1[i];
        a[scan1[i]] += 1;
    }
    int num = 0;
    int m = 0;
    for(int i = 0; i < 5100; i++){
        if(a[i] > 0){
            a[i]--;

            m = i;
            num++;
        }
    }
    for(int i = m-1; i >= 0; i--){
        if(a[i] > 0){
            a[i]--;

            num++;
        }
    }
    for(int i = 0; i < 5944; i++) a[i] = 0;
    for(int i = 0; i < n; i++){
        a[scan1[i]] += 1;
    }
    cout << num << endl;
    for(int i = 0; i < 5100; i++){
        if(a[i] > 0){
            a[i]--;
            cout << i << " ";
            m = i;
            num++;
        }
    }
    for(int i = m-1; i >= 0; i--){
        if(a[i] > 0){
            a[i]--;
            cout << i << " ";
            num++;
        }
    }   cout << endl;
    return 0;
}