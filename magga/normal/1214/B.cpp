#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int n,d,e;cin>>d>>e>>n;
    long long int answer=0;
    if(max(d,e)<n)
    {
        answer=e+d-n+1;
    }
    else if(min(d,e)>n)
    {
        answer=n+1;
    }
    else
    {
        answer=min(e,d)+1;
    }
    cout<<answer<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	solve(); 
}