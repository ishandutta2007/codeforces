#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int main()
{
    while(1)
    {
        cout<<"next 1 2"<<endl;
        cout.flush();

        int groups;
        cin>>groups;

        for(int i=1;i<=groups;i++)
        {
            string idle;
            cin>>idle;
        }

        cout<<"next 2"<<endl;
        cout.flush();

        cin>>groups;

        for(int i=1;i<=groups;i++)
        {
            string idle;
            cin>>idle;
        }



        if(groups==2)break;
    }

    while(1)
    {
        cout<<"next 0 1 2 3 4 5 6 7 8 9"<<endl;
        cout.flush();

        int groups;
        cin>>groups;

        for(int i=1;i<=groups;i++)
        {
            string idle;
            cin>>idle;
        }

        if(groups==1)break;
    }

    cout<<"done"<<endl;
    cout.flush();

    return 0;
}