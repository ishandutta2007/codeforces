#include<bits/stdc++.h>
using namespace std;
int T;
 
int main()
{
    cin>>T;
    while(T--)
    {
        int n,i;
        string s;
        cin>>n>>s;
        int a[n];
        for(i=0;i<n;i++)
            a[i] = 1;
            
        bool found1 = false,found2 = false;
        for(i=0;i<n;i++)
        {
            if(s[i] == '<')
                found1 = true;
            if(s[i] == '>')
                found2 = true;
            if(s[i] == '-')
            {
                a[i] = 0;
                a[(i+1)%n] = 0;
            }
        }
        
        if(found1 && found2)
        {
            int coun = 0;
            for(i=0;i<n;i++)
            {
                if(a[i] == 0)
                    coun++;
            }
            cout<<coun<<endl;
        }
        else
            cout<<n<<endl;
    }
}