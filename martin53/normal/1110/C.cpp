#include<bits/stdc++.h>
using namespace std;
int query()
{
    int num;
    cin>>num;
    int val=1;
    while(val<num)val=val*2+1;
    if(num!=val)return val;
    int ret=1;
    for(int i=2;i*i<=num;i++)
        if(num%i==0)
        {
            ret=max(ret,i);
            ret=max(ret,num/i);
        }
    /*
    int ret=0;
    for(int b=1;b<num;b++)
        ret=max(ret,__gcd(num&b,num^b));
    */
    return ret;
}
int main()
{
int q;
cin>>q;
for(int i=1;i<=q;i++)
    cout<<query()<<endl;

return 0;
}