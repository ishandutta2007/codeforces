#include<bits/stdc++.h>
using namespace std;

int main()
{
string outp;
cin>>outp;

if('a' <=outp[0]&&outp[0]<='z')outp[0]+='A'-'a';

cout<<outp<<endl;
}