#include<iostream>
#include<algorithm>
using namespace std;
int T,N,A[50];
main()
{
    cin>>T;
    for(;T--;)
    {
        cin>>N;
        for(int i=0;i<N;i++)cin>>A[i];
        sort(A,A+N);
        int ans=A[1]-A[0];
        for(int i=2;i<N;i++)ans=min(ans,A[i]-A[i-1]);
        cout<<ans<<endl;
    }
}