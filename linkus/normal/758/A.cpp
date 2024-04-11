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
    vector<int> vec(n);
    for(auto &i: vec)
        cin >> i;
    int max = *max_element(vec.begin(), vec.end());
    int num=0;
    for(auto &i: vec){
        num+=max-i;
    }
    cout << num;
}