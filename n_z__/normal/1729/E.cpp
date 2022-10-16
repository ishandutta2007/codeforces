#include<bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    for(int x=2;x<=26;x++)
    {
        cout<<"? 1 "<<x<<endl;
        cout<<"? "<<x<<" 1"<<endl;
        int an1=0,an2=0;
        cin>>an1>>an2;
        if(an1==-1||an2==-1){cout<<"! "<<x-1<<endl;return 0;}
        if(an1!=an2){cout<<"! "<<an1+an2<<endl;return 0;}
    }
}