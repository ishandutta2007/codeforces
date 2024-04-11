#include<bits/stdc++.h>
using namespace std;
long long a[3];

long long ret_max(long long i, long long j, long long k)
{
    long long arr[3] = {i,j,k};
    sort(arr,arr+3,greater<long long>());
    return arr[0];
}

int main()
{
    cin>>a[0]>>a[1]>>a[2];
    cout<<"First\n";
    fflush(stdout);
    long long maxi = ret_max(a[0],a[1],a[2]);
    cout<<maxi+1<<"\n";
    fflush(stdout);
    int cur;
    cin>>cur;
    a[cur-1]+=maxi;
    a[cur-1]++;
    maxi = 3*ret_max(a[0],a[1],a[2])-a[0]-a[1]-a[2];
    cout<<maxi<<"\n";
    fflush(stdout);
    cin>>cur;
    a[cur-1]+=maxi;
    sort(a,a+3);
    cout<<a[1]-a[0]<<"\n";
    fflush(stdout);
    cin>>cur;
    return 0;
}