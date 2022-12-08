#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

string poke[8] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
int l; string s;

int main()
{
    cin >> l >> s;
    for (int i=0;i<8;i++) if (poke[i].length() == s.length()){
        int good = 1;
        for (int j=0;j<s.length();j++){
            if (s[j] == '.') continue;
            if (s[j] != poke[i][j]){
                good = 0; break;
            }
        }
        if (good){
            cout << poke[i];
        }
    }

    return 0;
}