#include<iostream>
#include<string.h>
#define LL long long
using namespace std;
int a[1100][1100];
int main(){
    int n;
    char game[2100];
    cin >> n >> game;
    int len = strlen(game);
    int ans = 0;
    int i = 0;
    while(i < len){
        if(i >= 3){
            if(game[i-1] == game[i-2] && game[i-2] == game[i-3]){
                ans++;
            }
        }
        i += n;
    }
    cout << ans << endl;
}