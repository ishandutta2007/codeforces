#include <iostream>
using namespace std;

int main(){
    char c;
    long long r=0;
    while (cin.get(c))
    {
        int x=0;
        if (c=='>') x=8;
        else
        if (c=='<') x=9;
        else
        if (c=='+') x=10;
        else
        if (c=='-') x=11;
        else
        if (c=='.') x=12;
        else
        if (c==',') x=13;
        else
        if (c=='[') x=14;
        else
        if (c==']') x=15;
        else
        {
            cout<<r%1000003;
            return 0;
        }
        r<<=4;
        r%=1000003;
        r+=x;
        //cout<<x<<" "<<r<<endl;
    }
    cout<<r%1000003;
    return 0;
}