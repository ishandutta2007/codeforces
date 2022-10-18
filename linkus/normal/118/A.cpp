//Autor: Juliusz Korab-Karpowicz
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    const string vowels = "aoyeui";
    string str;
    cin >> str;
    for(size_t i=0;i<str.size();){
        if(vowels.find(tolower(str[i]))!=str.npos){
            str.erase(str.begin()+i);
        }
        else{
            if(isupper(str[i]))
                str[i] = tolower(str[i]);
            str.insert(str.begin()+i, '.');
            i+=2;
        }
    }
    cout << str;
}