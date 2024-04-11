#include<iostream>
#include<algorithm>
using namespace std;
int N;
string S;
main()
{
    cin>>N;
    for(;N--;)
    {
        cin>>S;
        bool ok=true;
        sort(S.begin(),S.end());
        for(int i=1;i<S.size();i++)
        {
            if(S[i-1]+1!=S[i])ok=false;
        }
        cout<<(ok?"YES":"NO")<<endl;
    }
}