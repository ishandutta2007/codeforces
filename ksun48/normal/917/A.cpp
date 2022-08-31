#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int ok[n][n];
    for(int a = 0; a < n; a++){
        for(int b = 0; b < n; b++){
            ok[a][b] = 1;
        }
    }
    for(int a = 0; a < n; a++){
        int sum = 0;
        int works = 1;
        for(int b = a; b < n; b++){
            if(b % 2 == a % 2) ok[a][b] = 0;
            sum += 1;
            if(s[b] == ')') sum -= 2;
            if(sum < 0) works = 0;
            if(!works) ok[a][b] = 0;
        }
    }
    for(int b = 0; b < n; b++){
        int sum = 0;
        int works = 1;
        for(int a = b; a >= 0; a--){
            sum += 1;
            if(s[a] == '(') sum -= 2;
            if(sum < 0) works = 0;
            if(!works) ok[a][b] = 0;
        }
    }
    int num = 0;
    for(int a = 0; a < n; a++){
        for(int b = a; b < n; b++){
            num += ok[a][b];
        }
    }
    cout << num << endl;
}