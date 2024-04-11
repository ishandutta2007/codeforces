#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> freq(26, 0);
    for(int i = 0; i < n; i++){
        freq[s[i]-'a']++;
    }
    int num1 = 0;
    for(int i = 0; i < 26; i++){
        num1 += (freq[i] >= 2);
    }
    if(n == 1 || num1 > 0){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}