/*Hina from weathering with you is the second best girl in anime history.*/
#include<bits/stdc++.h>
using namespace std;
int t;

int main()
{
    cin>>t;
    while(t--)
    {
        long long a,b,x,y;
        cin>>a>>b>>x>>y;
        long long disx = x-a+1;
        long long disy = y-b+1;
        long long mini = min(disx,disy);
        long long maxi = max(disx,disy);
        cout<<(mini-1)*(mini-2)+(maxi-mini+1)*(mini-1)+1<<"\n";
    }
    return 0;
}