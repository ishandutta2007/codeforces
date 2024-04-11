#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    int n;
    cin >> n;
    map<int,int> canmake;
    vector<int> num[n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 6; j++){
            int a;
            cin >> a;
            num[i].push_back(a);
            canmake[a]++;
        }
    }
    sort(num, num+n);
    while(1){
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                if(n >= 2) canmake[num[0][i] * 10 + num[1][j]]++;
                for(int k = 0; k < 6; k++){
                    if(n >= 3) canmake[num[0][i] * 100 + num[1][j] * 10 + num[2][k]]++;
                }
            }
        }
        if(!next_permutation(num, num+n)) break;
    }
    int c = 1;
    while(canmake[c]) c++;
    cout << c-1 << endl;

}