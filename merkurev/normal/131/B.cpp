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
unsigned long long q[100];
int main(){

    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        q[x+10]++;
    }
    unsigned long long r=0;
    for (int i=0;i<10;i++)
    {
        r+=q[i]*q[20-i];
    }
    r+=(q[10]*(q[10]-1))/2;
    cout<<r;
    return 0;
}