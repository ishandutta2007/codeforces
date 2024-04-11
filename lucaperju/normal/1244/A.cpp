#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d,k,i,j,t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>d>>k;
        int cata=0,catb=0;
        cata=(a-1)/c+1;
        catb=(b-1)/d+1;
        if(cata+catb>k)
        {
            cout<<-1<<'\n';
        }
        else
            cout<<cata<<' '<<catb<<'\n';
    }
    return 0;
}