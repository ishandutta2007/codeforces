#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int n,k;cin>>n>>k;
    long long int answer=0;
    while(n!=0)
    {
        if(n<k)
        {
            answer+=n;
            break;
            
        }
        else if(n%k==0)
        {
            answer++;
            n=n/k;
        }
        else
        {
            long long int i=n/k;
            answer+=n-k*i;
            n=i*k;
        }
    }
    cout<<answer<<endl;
}
int main()
{
    long long int num;
    cin>>num;
    for(long long int i=0;i<num;i++)
    {
       	solve();
    }   
}