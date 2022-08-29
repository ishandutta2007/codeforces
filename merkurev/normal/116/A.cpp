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
   // freopen("input.txt","rt",stdin);
   // freopen("output.txt","wt",stdout);
    int n,a,r=0,b,min=0;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a>>b;
        r=r-a+b;
        if (r>min) min=r;
    }
    cout<<min;
    return 0;
}