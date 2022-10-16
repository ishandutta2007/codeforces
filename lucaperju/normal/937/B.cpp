#include <iostream>

using namespace std;
int a;
/*bool prim(int x)
{
    int d;
    if(x==1) return 0;
    if(x%2==0&&x!=2) return 0;
    for(d=3; d*d<=x; d+=2)
        if(x%d==0) return 0;
    return 1;
}*/
bool verif (int val)
{
    int i;
    for(i=2;i*i<=val && i<=a;++i)
        if(!(val%i))
            return false;
    return true;
}
int main()
{
    int b,i,rez=-1,ca=a;
    cin>>a>>b;
    if(b%2==0)
        --b;
    for(i=b;i>a;--i)
    {
        if(verif(i))
        {
            rez=i;
            break;
        }
    }
    cout<<rez;
    return 0;
}