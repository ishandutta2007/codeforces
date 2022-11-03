#include <iostream>
using namespace std;
int main()
{
    string a;
    cin>>a;
    int s=a.size();
    for(int i=0;i<s;i++)
    {
        if(a[i]=='.')
        {
            if(i>0 && a[i-1]=='-')
                {
                    cout<<"1";
                    a.erase(i-1,2);
                    s=a.size();
                    i=-1;
                }
            else if(i<1)
                {cout<<"0"; a.erase(i,1); s=a.size(); i=-1;}
        }
        if(a[i]=='-')
        {
            if(i>0 && a[i-1]=='-')
            {
                cout<<"2"; a.erase(i-1,2);
                s=a.size();
                i=-1;
            }
        }
    }
}