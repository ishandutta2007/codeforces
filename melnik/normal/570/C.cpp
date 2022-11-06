#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n,m,kol=0,i[300000],z;
    string s;
    char t;
    cin>>n>>m>>s;
    for (z=0;z<n;z++)
        i[z]=0;
    for (z=0;z<n;z++)
        if (s[z]=='.') i[z]=i[z-1]+1;
    for (z=0;z<n;z++)
        if (i[z]>1) kol++;
    s='%'+s+'%';
    for (;m>0;m--){
        cin>>n>>t;
        if (t!='.'&&s[n]!='.') cout<<kol<<endl;
        if (t!='.'&&s[n]=='.') {
            if (s[n-1]=='.') kol--;
            if (s[n+1]=='.') kol--;
            cout<<kol<<endl;
        }
        if (t=='.'&&s[n]=='.') cout<<kol<<endl;;
        if (t=='.'&&s[n]!='.') {
            if (s[n-1]=='.') kol++;
            if (s[n+1]=='.') kol++;
            cout<<kol<<endl;
        }
        s[n]=t;
    }
    return 0;
}