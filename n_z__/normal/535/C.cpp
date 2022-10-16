#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int a,b,n;
    cin>>a>>b>>n;
    for(int x=1;x<=n;x++)
    {
        int l,t,m;
        cin>>l>>t>>m;
        if(t<a+(l-1)*b){cout<<-1<<endl;continue;}
        int L=1,R=(t-a)/b+1,M=(L+R+1)/2;
        while(M=(L+R+1)/2,L<R)
        if((2*a+(l+M-2)*b)*(M-l+1)>t*m*2)R=M-1;
        else L=M;
        cout<<min(R,(t-a+b)/b)<<endl;
    }
}