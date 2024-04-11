#include<bits/stdc++.h>
using namespace std;

int const nax = 3e5 + 10;
long long a[4];


int main(){
    int t;
    for(cin >> t ; t -- ; ){
        for(int i = 1 ;i <= 3 ; i ++)
            cin >> a[i];
        sort(a + 1,  a + 1 + 3);
        if(a[1] + a[2] >= a[3] - 1){
            printf("Yes\n");
        }
        else printf("No\n");
    }
}
/**
    Good Luck
        -Lucina
*/