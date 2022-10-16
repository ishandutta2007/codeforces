#include <bits/stdc++.h>

using namespace std;
int ask (int a, int b)
{
    cout<<"? "<<a<<' '<<b<<'\n';
    cout.flush();
    int rz;
    cin>>rz;
    return rz;
}
int main()
{
    long long a=0,b=0,big,i;
    big=ask(0,0);
    for(i=1LL<<29;i>0;i>>=1LL)
    {
        int rz1=ask(a|i,b);
        if(big==0)
        {
            if(rz1==-1)
            {
                a|=i;
                b|=i;
            }
        }
        else if (rz1==0)
        {
            int rz2=ask(a,b);
            if(rz2==1)
                a|=i;
            else
                b|=i;
            big=0;
        }
        else
        {
            int rz2=ask(a,b|i);
            if(rz1!=rz2)
            {
                if(rz1==-1)
                {
                    a|=i;
                    b|=i;
                }
            }
            else
            {
                if(big==1)
                    a|=i;
                else
                    b|=i;
                big=rz1;
            }
        }
    }
    cout<<"! "<<a<<' '<<b;
    cout.flush();
}