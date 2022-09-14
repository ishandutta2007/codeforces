#include<iostream>
using namespace std;
int T;
main()
{
    cin>>T;
    for(;T--;)
    {
        int N;cin>>N;
        int c[4]={};
        for(int i=0;i<N;i++)
        {
            int a;cin>>a;
            c[a%2*2+i%2]++;
        }
        if(c[1]!=c[2])cout<<-1<<endl;
        else cout<<c[1]<<endl;
    }
}