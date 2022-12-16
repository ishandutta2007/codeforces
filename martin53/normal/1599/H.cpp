#include<bits/stdc++.h>
using namespace std;

const int inf=1e9;

long long ask(int x,int y)
{
    cout<<"? "<<x<<" "<<y<<endl;

    long long ret;
    cin>>ret;
    return ret;
}

int main()
{
    long long x_mid=(ask(1,1)-ask(inf,1)+inf+1)/2;
    int y=ask(x_mid,1)+1;
    int q=inf-ask(x_mid,inf);

    long long y_mid=(ask(1,1)-ask(1,inf)+inf+1)/2;
    int x=ask(1,y_mid)+1;
    int p=inf-ask(inf,y_mid);

    cout<<"! "<<x<<" "<<y<<" "<<p<<" "<<q<<endl;

    return 0;
}