#include<bits/stdc++.h>
using namespace std;
long long int m,i,j,k,l,n,s;
vector<long long int> v;
long long cou;
int main()
{
    cin>>n>>m>>k;
    for(i=0;i<n;i++)
    {
        cin>>s;
        v.push_back(s);
    }
    sort(v.begin(),v.end());
    cout<<v[n-2]*(m/(k+1))+v[n-1]*(m-m/(k+1));
    return 0;
}