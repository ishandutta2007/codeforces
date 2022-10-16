#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


string str;
const string S = "CODEFORCES";

void input(){
	cin >> str;
}

int main(){
	input();
    if(str == S){
        cout << "YES\n";
        return 0;
    }

    int N = (int)str.size();

    for(int i = 0; i <= 10; i++){
        bool ok = true;

        for(int l = 0; l < i; l++){
            if(str[l] != S[l]) ok = false;
        }

        for(int r = 0; r < 10-i; r++){
            if(str[N-r-1] != S[9-r]) ok = false;
        }

        if(ok){
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
}