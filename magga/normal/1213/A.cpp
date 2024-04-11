#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int n,d;cin>>n;
    long long int odd=0;
    for(long long int i=0;i<n;i++)
    {
        cin>>d;
        if(d%2!=0)
        {
            odd++;
        }
    }
    if(odd<n-odd)
    {
        cout<<odd<<endl;
    }
    else
    {
        cout<<n-odd<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	solve(); 
}