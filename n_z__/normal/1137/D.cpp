#include<bits/stdc++.h>
using namespace std;
int get(string s)
{
    cout<<"next "<<s<<endl;
    int x;
    cin>>x;
    for(int i=0;i<x;i++)
    cin>>s;
    return x;
}
main()
{
    do get("0 1");
    while(get("0")!=2);
    while(get("0 1 2 3 4 5 6 7 8 9")!=1);
    cout<<"done"<<endl;
}