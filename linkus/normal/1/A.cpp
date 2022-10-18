//Autor: Juliusz Korab-Karpowicz
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    unsigned long long n, m, a;
    cin >> n >> m >> a;
    cout << ((n+a-1)/a)*((m+a-1)/a);
}