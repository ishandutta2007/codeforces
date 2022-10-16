#include<bits/stdc++.h>
using namespace std;

/*
    *
    * Prosen Ghosh
    * American International University - Bangladesh (AIUB)
    *
*/

int main(){

    long long int n,b[200005],val = 0,cnt = 0;
    cin >> n;
    for(int i = 0; i < n; i++)cin >> b[i];

    val = 0;

    for(int i = 0; i < n; i++){

        if(val < b[i]){
            while(val != b[i]){val++;cnt++;}
        }
        else if(val > b[i]){
            while(val != b[i]){val--;cnt++;}
        }
    }
    cout << cnt << endl;
    return 0;
}