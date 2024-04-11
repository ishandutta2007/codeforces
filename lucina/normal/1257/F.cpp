#include<bits/stdc++.h>
using namespace std;
int const nax = 105;
int n, a[nax];
map<vector<int> ,int > sv;

int main(){
    /// meet in the middle approach
    scanf("%d", &n);
    for(int i = 1 ;i <= n ;i ++){
        scanf("%d", &a[i]);
    }
    int const mask = (1 << 15) - 1;
    vector<int > touse;
    for(int x = 0 ; x <= mask ; x ++){
        touse.clear();
        for(int i =  1 ;i <= n ;i++){
            touse.push_back(__builtin_popcount((a[i] & mask) ^ x));
        }
        for(int i = 1 ; i < (int)touse.size() ; i++)
            touse[i] -= touse[0];
        touse[0] = 0;
        sv[touse] = x;
    }
    map<vector<int> , int> :: iterator it ;
    for(int x = 0 ; x <= mask ; x ++){
        touse.clear();
        for(int i = 1 ;i <= n ; i ++){
            touse.push_back(30 - __builtin_popcount( (a[i] >> 15) ^ x));
        }
        for(int i = 1 ; i < (int)touse.size() ; i++){
            touse[i] -= touse[0];
        }
        touse[0] = 0;
        it = sv.find(touse);
        if(it != sv.end()){
            return !printf("%d\n", (x << 15) + it -> second);
        }
    }
    printf("-1");
}