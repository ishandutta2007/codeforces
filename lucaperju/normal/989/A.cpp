#include <iostream>
#include <cstring>
using namespace std;
char s[105];
bool verif (char a, char b, char c)
{
    int a1=0,a2=0,a3=0;
    if(a=='A' || b=='A' || c=='A')
        a1=1;
    if(a=='B' || b=='B' || c=='B')
        a2=1;
    if(a=='C' || b=='C' || c=='C')
        a3=1;
    if(a1==1 && a2==1 && a3==1)
        return true;
    return false;
}
int main()
{
    int a,ok=0;
    cin>>s;
    a=strlen(s);
    for(int i=1;i<a-1;++i)
    {
        if(verif(s[i-1],s[i],s[i+1]))
        {
            cout<<"Yes";
            ok=1;
            break;
        }
    }
    if(ok==0)
        cout<<"No";
    return 0;
}