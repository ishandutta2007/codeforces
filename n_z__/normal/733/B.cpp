#include<bits/stdc++.h>
using namespace std;
int main()
{
    int nowl=0,nowr=0,n,nowlid=1,nowrid=1,suml=0,sumr=0;
    cin>>n;
    for(int x=1;x<=n;x++)
    {
        int y,z;
        cin>>y>>z;
        if(y>z&&y-z>=nowl)nowl=y-z,nowlid=x;
        if(y<z&&z-y>=nowr)nowr=z-y,nowrid=x;
        suml+=y;
        sumr+=z;
    }
    //cout<<nowl<<','<<nowr<<','<<nowlid<<','<<nowrid<<','<<suml<<','<<sumr<<endl;
    if(nowl*nowr==0)cout<<0<<endl;
    else if(abs(suml-sumr-2*nowl)>=abs(suml-sumr+2*nowr))cout<<nowlid;
    else cout<<nowrid;
}