#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

int main(){
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    char c;
    while (cin.get(c))
    {
        if (c=='H' || c=='Q' || c=='9')
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}