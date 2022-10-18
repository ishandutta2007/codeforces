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
    if(n==2)
        cout << "NO";
    else
        cout << (n%2?"NO":"YES");
}