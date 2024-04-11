#include<bits/stdc++.h>
using namespace std;
int T;

int main()
{
    cin>>T;
    while(T--)
    {
        int n,k,i;
        vector<int> v;
        cin>>n>>k;
        for(i=0;i<n;i++)
        {
            int a;
            cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end(),greater<int>());
        long long sum = 0;
        for(i=0;i<min(k+1,n);i++)
            sum+=v[i];
        cout<<sum<<endl;
    }
    return 0;
}