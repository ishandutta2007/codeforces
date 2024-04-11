#include<iostream>
#include<algorithm>
using namespace std;
int A[4];
main()
{
    for(int i=0;i<4;i++)cin>>A[i];
    sort(A,A+4);
    cout<<A[3]-A[0]<<" "<<A[3]-A[1]<<" "<<A[3]-A[2]<<endl;
}