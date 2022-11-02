#include<bits/stdc++.h>
using namespace std;
long long i,miss;
string a,b;

bool check(char p)
{
    if(p=='a'||p=='e'||p=='i'||p=='o'||p=='u')
    {
        return true;
    }
    else 
    {
        return false;
    }
}

int main() {
    cin>>a;
    cin>>b;
    double e=a.length();
    double r=b.length();
    if(e != r)
    {cout<<"No";}
    else
    {
        for(i=0;i<e;i++)
        {
            if(check(a.at(i)) && check(b.at(i)))
            {}
            else if (!check(a.at(i)) && !check(b.at(i)))
            {}
            else {miss++;}
        }
        if(miss)
        {
            cout<<"No";
        } else {cout<<"Yes";}
    }
}