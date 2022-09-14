#include<iostream>
#include<algorithm>
using namespace std;
int N;
main()
{
    cin>>N;
    vector<pair<int,int> >A(N);
    for(int i=0;i<N;i++)
    {
        A[i].second=i;
        scanf("%d",&A[i].first);
    }
    sort(A.begin(),A.end());
    reverse(A.begin(),A.end());
    int ans=0;
    for(int i=0;i<N;i++)ans+=A[i].first*i+1;
    cout<<ans<<endl;
    for(int i=0;i<N;i++)cout<<A[i].second+1<<(i+1==N?"\n":" ");
}