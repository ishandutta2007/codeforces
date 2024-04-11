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
   // freopen("output.txt","wt",stdout);
    string a,b;
    int c=0,d=0;
    cin>>a;
    cin>>b;
    for (int i=0;i<a.length();i++)
        if (a.at(i)=='4' && b.at(i)=='7')
            c++;
        else
            if (a.at(i)=='7' && b.at(i)=='4')
                d++;
    int r=c>d?c:d;
    cout<<r;
    return 0;
}