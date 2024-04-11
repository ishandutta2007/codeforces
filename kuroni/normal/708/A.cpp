#include<bits/stdc++.h>
using namespace std;
main()
{
    string str;
    cin>>str;
    int i = 0, j = str.length();
    while (i<j&&str[i]=='a') i++;
    if (i==j) str[i-1]='z';
    while (i<j&&str[i]!='a') {str[i]--;i++;}
    cout<<str;
}