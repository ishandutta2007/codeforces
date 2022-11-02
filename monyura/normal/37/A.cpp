#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int n;
    int A[1001]={0};
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        A[a]++;
    }
    int mx=0;
    for (int i=0;i<1001;i++)
        if (A[i]>=mx) mx=A[i];
    cout<<mx<<' ';
    int cnt=0;
    for (int i=0;i<1001;i++)
        if (A[i]!=0) cnt++;
    cout<<cnt<<endl;
    return 0;
}