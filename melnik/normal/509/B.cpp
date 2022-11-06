#include <iostream>

using namespace std;

int main()
{
    int n,k,i[100],t,ma=-1,mi=1000,izm,q;
    cin>>n>>k;
    for (t=0;t<n;t++)
    {
        cin>>i[t];
        if (i[t]>ma) ma=i[t];
        if (i[t]<mi) mi=i[t];
    }
    if (mi+k<ma) cout<<"NO";
    else
    {
        cout<<"YES"<<endl;
        for (t=0;t<n;t++)
        {
            izm=0;
            while (izm!=mi) {cout<<1<<' ';izm++;};
            i[t]-=mi;
            q=1;
            while (i[t]!=0) {cout<<q<<' '; q++; i[t]--;}
            cout<<endl;
        }
    }
    return 0;
}