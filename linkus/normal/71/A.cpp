//Autor: Juliusz Korab-Karpowicz
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string tmp;
    while(n--){
        cin >> tmp;
        if(tmp.size()<=10)
            cout << tmp << '\n';
        else{
            cout << tmp.front() << tmp.size()-2 << tmp.back() << '\n';;
        }
    }
}