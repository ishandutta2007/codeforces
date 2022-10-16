#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
char v[200];
int main()
{
    int a,i;
    for(i=0;i<=5;++i)
    {
        cout<<i<<'\n';
        cin.getline(v,100);
        cout.flush();
        if(v[0]=='g' && v[1]=='o' || v[0]=='w' || v[0]=='t' || v[0]=='a' || v[0]=='d' && v[6]=='e')
        {
            cout<<"grumpy";
            return 0;
        }
    }
    cout<<"normal";
}