#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL a[110000];
int main(){
    LL h;
    cin >> h;

    for(int i = 0; i <= h; i++){
        cin >> a[i];
    }
    int perf = 1;
    for(int i = 0; i < h; i++){
        if(a[i] >= 2 && a[i+1] >= 2){
            perf = 0;
        }
    }
    if(perf){
        cout << "perfect" << endl;
        return 0;
    }
    cout << "ambiguous" << endl;
    int last = 0;
    // tree1
    for(int i = 0; i <= h; i++){
        if(i == 0 || a[i] == 1 || a[i-1] == 1){
            for(int j = 0; j < a[i]; j++){
                cout << last << " ";
            }
        } else {
            for(int j = 0; j < a[i]; j++){
                cout << last << " ";
            }
        }
        last += a[i];
    }
    cout << endl;
    last = 0;
    for(int i = 0; i <= h; i++){
        if(i == 0 || a[i] == 1 || a[i-1] == 1){
            for(int j = 0; j < a[i]; j++){
                cout << last << " ";
            }
        } else {
            for(int j = 0; j < a[i]; j++){
                cout << last - (j % 2) << " ";
            }
        }
        last += a[i];
    }
    cout << endl;
}