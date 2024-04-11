#include<bits/stdc++.h>
using namespace std;
int n;
bool ask(int r1,int c1,int r2,int c2)
{
    if(r1>r2)swap(r1,r2);
    if(c1>c2)swap(c1,c2);
    if(r1==0||r2>n)return 0;
    if(c1==0||c2>n)return 0;
    cout<<"? "<<r1<<" "<<c1<<" "<<r2<<" "<<c2<<endl;
    cout.flush();
    string ans;
    cin>>ans;
    return (ans=="YES");
}
int main()
{
    cin>>n;
    string s1="";
    int x1=1,y1=1;
    while(x1+y1!=n+1)
    {
        if(ask(n,n,x1+1,y1))s1=s1+"D",x1++;
        else s1=s1+"R",y1++;
    }

    string s2="";
    int x2=n,y2=n;
    while(x2+y2!=n+1)
    {
        if(ask(1,1,x2,y2-1))s2="R"+s2,y2--;
        else s2="D"+s2,x2--;
    }
    //reverse(s2.begin(),s2.end());
    cout<<"! "<<s1<<s2<<endl;
}