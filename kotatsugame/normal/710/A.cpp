#include<iostream>
using namespace std;
string s;
int dx[8]={0,1,0,-1,1,1,-1,-1};
int dy[8]={1,0,-1,0,1,-1,1,-1};
main()
{
    cin>>s;
    int x=s[0]-'a',y=s[1]-'1';
    int cnt=0;
    for(int r=0;r<8;r++)
    {
        int tx=x+dx[r],ty=y+dy[r];
        if(tx>=0&&tx<8&&ty>=0&&ty<8)cnt++;
    }
    cout<<cnt<<endl;
}