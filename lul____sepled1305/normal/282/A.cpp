#include<iostream>
using namespace std;
int n,val,ca,des;
string s;

int main()
{
    cin>>n;
    while(n--)
    {
        cin>>s;
        if(s.at(0)=='X')
            des = 1;
        else
            des = 0;
        
        if(s.at(des)=='+')
            val++;
        else
            val--;
    }
    cout<<val;
    return 0;
}