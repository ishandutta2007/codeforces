#include <iostream>
using namespace std;
long long t[200005],cat[200005];
int main()
{
    int n,m,i,j,ok=0;
    cin>>n;
    while(n--)
    {
        int a,b,c,r;
        cin>>a>>b>>c>>r;
        int st=c-r,dr=c+r;
        if(a>b)
            swap(a,b);
        if(a>dr || b<st)
        {
            cout<<b-a<<'\n';
            continue;
        }
        int s=0;
        s+=max(0,b-dr);
        s+=max(0,st-a);
        cout<<s<<'\n';
    }
}