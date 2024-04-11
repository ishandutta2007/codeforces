#include <iostream>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;

string s[600];

void func(int n)
{
    if (n==1) {s[0][0]='+'; return ;}
    int a=n/2;
    func(a);

    //top right
    for (int i=0; i<a;i++)
        for (int j=a; j<n;j++) s[i][j]=s[i][j-a];
    //bottom left
    for (int i=a; i<n;i++)
        for (int j=0; j<a;j++) s[i][j]=s[i-a][j];
    //bottom right
    for (int i=a; i<n;i++)
        for (int j=a; j<n;j++)
        if (s[i-a][j-a]=='+') s[i][j]='*';
        else s[i][j]='+';
}
/*
int comp(string s1, string s2)
{
    int ch=0;
    for (int i=0;i<s1.length();i++)
    if (s1[i]!=s2[i]) ch--; else ch++;
    return ch;
}*/

int main()
{
    int k,n;
    cin>>k;
    n = (int)pow(2,k);
    //cout<<n<<endl;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++) s[i].push_back('1');
    //for (int i=0;i<n;i++) cout<<s[i]<<endl;

    func(n);
    for (int i=0;i<n;i++) cout<<s[i]<<endl;

    return 0;
}