#include <iostream>
using namespace std;
int main()
{
    string a;
    cin>>a;
    int baz=0,baste=0,tag=0,s;
    s=a.size();
    int t=0;
    for(int i=0;i<s;i++)
    {
        if(a[i]==')')
            {
                baste++;
                if(t>0)
                    t--;
            }
        else if(a[i]=='(')
            {baz++; t++;}
        else
           {tag++; t=0;}
        if(tag>baz-baste)
            {cout<<-1;
        return 0;}
    }
    if(baz<baste+tag || t>0) {cout<<-1; return 0;}
        baz-=baste;
    for(int i=0;i<tag-1;i++,baz--)
        cout<<1<<endl;
    cout<<baz;
}