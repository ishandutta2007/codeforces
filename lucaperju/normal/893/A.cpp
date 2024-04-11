#include <iostream>

using namespace std;
int main()
{
    int n,i,j,cur1,cur2;
    cin>>n;
    cur1=1;
    cur2=2;
    for(i=1;i<=n;++i)
    {
        int a;
        cin>>a;
        if(a==cur1 || a==cur2)
        {
            if(a==cur1)
            {
                if(cur1==1 && cur2==2 || cur2==1 && cur1==2)
                    cur2=3;
                else
                if(cur1==2 && cur2==3 || cur2==2 && cur1==3)
                    cur2=1;
                else
                if(cur1==1 && cur2==3 || cur2==1 && cur1==3)
                    cur2=2;
            }
            else
            {
                if(cur1==1 && cur2==2 || cur2==1 && cur1==2)
                    cur1=3;
                else
                if(cur1==2 && cur2==3 || cur2==2 && cur1==3)
                    cur1=1;
                else
                if(cur1==1 && cur2==3 || cur2==1 && cur1==3)
                    cur1=2;
            }
        }
        else
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}