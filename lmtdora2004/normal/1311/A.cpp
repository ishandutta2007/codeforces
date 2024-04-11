#include<bits/stdc++.h>

using namespace std;

signed main()
{
    int tests;
    cin>>tests;
    for(int test=1; test<=tests; test++)
    {
        int a, b;
        cin>>a>>b;
        if(a==b)
        {
        	cout<<0<<endl;
        }
        if(a>b)
        {
            if((a-b)%2==0)
            {
            	cout<<1<<endl;
            }
            else
            {
            	cout<<2<<endl;
            }
        }
        if(a<b)
        {
            if((a-b)%2==0) 
            {
            	cout<<2<<endl;
            }
            else
            {
            	cout<<1<<endl;
            }
       	}
    }
}