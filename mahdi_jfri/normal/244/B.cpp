#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
set<int>a;
int n;
void tedad(ll b,int i, int j)
{
    if(b <= n)
    {
        if(b > 0)
            a.insert(b);
        if(b+i > 0)
            tedad(b*10+i,i,j);
        if(b+j > 0)
            tedad(b*10+j,i,j);
    }
}
int main()
{
    cin >> n;
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            tedad(0,i,j);
    cout << a.size();
}