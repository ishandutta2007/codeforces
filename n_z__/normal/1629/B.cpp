#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,r,k;
		cin>>l>>r>>k;
		if(k<(r+1)/2-(l/2)&&(l<r||l==1))cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
    }
}