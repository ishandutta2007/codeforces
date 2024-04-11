#include<bits/stdc++.h>
using namespace std;
int n,i=1,j=2;
char p[500000];
int main()
{
    cin>>n;
    scanf("%s",&p);
        cout<<"\n";
    while(i<=n)
    {
        cout<<p[i-1];
        i+=j;
        j++;
    }
    return 0;
}