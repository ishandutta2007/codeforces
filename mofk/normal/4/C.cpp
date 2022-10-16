#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <string>
#include <cstdio>
#include <vector>
#include <bitset>
using namespace std;

int main()
{   
    int n;
    cin >> n;
    getchar();
    string a;


    map <string, int> mp;

    for(int i = 0; i < n; i++) {
        getline(cin, a);
        if(mp[a] == 0) cout << "OK\n";
        else {
            cout << a << mp[a] << endl;
        }
        mp[a]++;
    }



    return 0;
}