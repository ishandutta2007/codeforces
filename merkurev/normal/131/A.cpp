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
    char c[1005];
    cin.getline(c,1000);
    bool n=true;
    for (int i=1;c[i];i++)
    {
        if (c[i]>='a' && c[i]<='z') n=false;
    }
    if (n)
    {
        if (c[0]>='a' && c[0]<='z') 
            c[0]=c[0]+'A'-'a';
        else
            c[0]=c[0]+'a'-'A';
        for (int i=1;c[i];i++)
        {
            c[i]=c[i]+'a'-'A';
        }
    }
    for (int i=0;c[i];i++)
        cout<<c[i];
    return 0;
}