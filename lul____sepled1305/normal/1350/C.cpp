#include<bits/stdc++.h>
using namespace std;
long long n,i,a,b,lc,ans=1LL;
vector<long long> prime;
vector<long long> arr[200020];

long long gc(long long a, long long b)
{
    if(a>b)
        swap(a,b);
    if(b%a==0)
        return a;
    else
        return gc(b%a,a);
}

int main()
{
    cin>>n>>a>>b;
    lc = a*b/gc(a,b);
    while(lc > 1)
    {
        for(i=2;i<200000;i++)
        {
            long long counti = 0;
            while(lc%i==0)
            {
                counti++;
                lc/=i;
            }
            if(counti)
            {
                prime.push_back(i);
            }
        }
    }
    for(auto it: prime)
    {
        long long counti = 0;
        while(a%it==0)
        {
            counti++;
            a/=it;
        }
        arr[it].push_back(counti);
    }
    for(auto it: prime)
    {
        long long counti = 0;
        while(b%it==0)
        {
            counti++;
            b/=it;
        }
        arr[it].push_back(counti);
    }
    for(i=2;i<n;i++)
    {
        cin>>a;
        for(auto it: prime)
        {
            long long counti = 0;
            while(a%it==0)
            {
                counti++;
                a/=it;
            }
            sort(arr[it].begin(), arr[it].end());
            if(counti < arr[it][1])
            {
                arr[it].pop_back();
                arr[it].push_back(counti);
            }
        }
    }
    for(auto it: prime)
    {
        sort(arr[it].begin(), arr[it].end());
        while(arr[it][1]>0)
        {
            ans*=it;
            arr[it][1]--;
        }
    }
    cout<<ans;
    return 0;
}