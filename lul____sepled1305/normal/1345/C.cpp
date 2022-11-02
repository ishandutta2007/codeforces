#include<bits/stdc++.h>
using namespace std;
int t;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(i=0;i<n;i++)
            arr[i] = 0;
        bool suc = true;
        for(i=0;i<n;i++)
        {
            cin>>j;
            j = ((j%n)+n)%n;
            arr[(i + j%n)%n]++;
            if(arr[(i + j%n)%n] >=2)
                suc = false;
        }
        if(suc)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}