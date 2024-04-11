#include<bits/stdc++.h>
using namespace std;
int main()
{
    int w,m;
    cin>>w>>m;
    while(m!=0)
    {
    //cout<<w<<','<<m<<endl;
        if(m%w==1)m--;
        else if(m%w==w-1)m++;
        if(!(m%w==0))return puts("NO")*0;
        m/=w;
    }
    puts("YES");
}