#include <iostream>
#include <cstring>
using namespace std;
char v[400005];
int main()
{
    int n,i,k;
    char c='a';
    cin>>n>>k>>v;
    for(c='a';c<='z' && k;++c)
    {
        for(i=0;i<n;++i)
        {
            if(v[i]==c && k)
            {
                --k;
                v[i]=-1;
                if(k==0)
                    break;
            }
        }
    }
    for(i=0;i<n;++i)
        if(v[i]!=-1)
            cout<<v[i];
    return 0;
}