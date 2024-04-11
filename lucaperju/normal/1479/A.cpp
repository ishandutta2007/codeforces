#include <bits/stdc++.h>
using namespace std;
int v[100003];
int query (int pz)
{
    cout<<"? "<<pz<<'\n';
    cout.flush();
    int a;
    cin>>a;
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,n,i,j,m,k=0;
    cin>>n;
    int st=1,dr=n;
    while(st<dr)
    {
        int mid=(st+dr)/2;
        int a=query(mid);
        int b=query(mid+1);
        if(a<b)
            dr=mid;
        else
            st=mid+1;
    }
    cout<<"! "<<st<<'\n';
    cout.flush();
    return 0;
}