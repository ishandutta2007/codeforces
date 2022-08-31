#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <bitset>
#include <cstdlib>

typedef long long ll;
typedef long double ld;

using namespace std;

const int MAX_N=201000;


int n,k,m;


string s;



bool eq(char a,char b)
{
    if (a=='A' && b=='A')
        return true;
    if (a=='H' && b=='H')
        return true;
    if (a=='I' && b=='I')
        return true;
    if (a=='M' && b=='M')
        return true;
    if (a=='O' && b=='O')
        return true;
    if (a=='T' && b=='T')
        return true;
    if (a=='U' && b=='U')
        return true;
    if (a=='V' && b=='V')
        return true;
    if (a=='W' && b=='W')
        return true;
    if (a=='X' && b=='X')
        return true;
    if (a=='Y' && b=='Y')
        return true;
    return false;

}



int main()
{
    ios_base::sync_with_stdio(false);

    cin>>s;

    for (int i=0;i<s.size();++i)
    {
        if (!eq(s[i],s[s.size()-i-1]))
        {
            cout<<"NO";
            return 0;
        }

    }
    cout<<"YES";
    return 0;
}