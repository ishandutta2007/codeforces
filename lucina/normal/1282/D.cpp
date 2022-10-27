#include<bits/stdc++.h>
using namespace std;
int n;
int ask(string s){
    cout << s << endl;
    int x;
    cin >> x;
    if(x == 0)
        exit(0);
    return x;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 1 ;i <= 300 ; i ++)
        cout << 'a';
    cout << endl;
    int x ;
    cin >> x;
    int a = 300 - x;
    for(int i = 1 ; i <= 300 ; i ++)
        cout << 'b';
    cout << endl;
    cin >> x;
    int b = 300 - x;
    n = a + b;
    string s;
    for(int i = 1; i <= n; i ++)
        s += 'a';
    if(n == 1){
        if(a) ask("a");
        else ask("b");
    }
    int cur = /*ask(s)*/ b;
    for(int i = n - 1;i >= 1 ; i --){
        s[i] = 'b';
        x = ask(s);
        if(x < cur){
            cur = x;
            s[i] = 'b';
        }
        else s[i] = 'a';
    }
    for(int i = n - 1 ;i >= 1 ; i --){
        if(s[i] == 'a') a --;
        else b --;
    }
    s[0] = a ? 'a' : 'b';
    ask(s);
}