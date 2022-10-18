//Autor: Juliusz Korab-Karpowicz
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int n,k;
    cin >> n >> k;
    vector<int> vec;
    copy_n(istream_iterator<int>(cin), n, back_inserter(vec));
    int num=0;
    int min=vec[k-1];
    for(auto &i: vec){
        if(i>=min && i>0)
            num++;
        else
            break;
    }
    cout << num;
}