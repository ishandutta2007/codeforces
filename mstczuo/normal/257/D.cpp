# include <iostream>
# include <cstdio>
using namespace std;
int n,a[100001],c[100001];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int s=0;
    for(int i=n-1;i>=0;i--)
        if(s>0)s-=a[i];
        else{c[i]=1;s+=a[i];}
    if(s<0)
        for(int i=0;i<n;i++)
            c[i]^=1;
    for(int i=0;i<n;i++)
        cout<<(c[i]?'+':'-');
    cout<<endl;
    return 0;
}