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
int q[105];
int main(){
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>q[i];
    sort(q,q+n);
    int t=0,r=0;
    int i=0;
    while (t+q[i]<=710 && i<n)
    {
        t+=q[i++];
        if (t>350)
        {
            r+=t-350;
        }
    }
    cout<<i<<" "<<r<<endl;
    return 0;
}