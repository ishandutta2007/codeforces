#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+10;
int n,i;
long long white,black;
int a[N];

int main()
{
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]%2==1)
        {
            if(i%2==1)
                white++;
            else
                black++;
        }
        white+=a[i]/2;
        black+=a[i]/2;
    }
    cout<<min(white,black);
    return 0;
}