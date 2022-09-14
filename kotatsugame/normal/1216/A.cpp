#include<iostream>
using namespace std;
int N;
string S;
main()
{
    cin>>N>>S;
    int cnt=0;
    for(int i=0;i<N;i+=2)
    {
        if(S[i]==S[i+1])
        {
            cnt++;
            S[i+1]='a'+'b'-S[i+1];
        }
    }
    cout<<cnt<<endl<<S<<endl;
}