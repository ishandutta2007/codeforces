#include<bits/stdc++.h>
using namespace std;

long long n,m,i,j,a,b;
char s[1000000];
string k;
long long leftb,rightb;
long long counti;

int main()
{
    cin>>n;
    cin>>k;
    //char mmm=k.at(0);
    //cout<<mmm;
    long long before=-1, after=-1;
    i=0;
    //cout<<k.at(0);
    while(i<n)
    {
        //cout<<k.at(i);
        if(k.at(i)=='(') {leftb++;}
        if(k.at(i)==')') {rightb++;}
        if(leftb<rightb && before==-1) {before = i;}
        if(leftb>=rightb && after==-1 && before!=-1) {after = i;}
        if(before!=-1 && after!=-1)
        {
            counti+=after-before+1;
            before=-1;
            after=-1;
        }
        i++;
    }
    //cout<<i;
    if(leftb==rightb) cout<<counti;
    else cout<<-1;
    return 0;
}