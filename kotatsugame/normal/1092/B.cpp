#include<iostream>
#include<algorithm>
using namespace std;
int N,A[100];
main()
{
    cin>>N;
    for(int i=0;i<N;i++)cin>>A[i];
    int ans=0;
    sort(A,A+N);
    for(int i=0;i<N;i+=2)ans+=A[i+1]-A[i];
    cout<<ans<<endl;
}