#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
string str[20];
int c[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,4,9,25,49};
int main()
{
    for(int i=0;i<19;i++) cout<<c[i]<<endl,cin>>str[i],fflush(stdout);
    bool ok=true;
    int cnt=0;
    for(int i=0;i<15;i++)
        if(str[i]=="yes") ok=false,cnt++;
    if(ok) {cout<<"prime"<<endl;return 0;}
    if(cnt>=2) {cout<<"composite"<<endl;return 0;}
    ok=true;
    for(int i=15;i<19;i++)
        if(str[i]=="yes") ok=false;
    if(ok) cout<<"prime"<<endl;
    else cout<<"composite"<<endl;
    return 0;
}