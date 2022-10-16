#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n,i,cntq=0,cntqa=0,cntqaq=0;
    char v[150];
    cin>>v;
    n=strlen(v);
    for(i=0;i<n;++i)
    {
        if(v[i]=='Q')
        {
            cntq++;
            cntqaq+=cntqa;
        }
        if(v[i]=='A')
        {
            cntqa+=cntq;
        }
    }
    cout<<cntqaq;
    return 0;
}