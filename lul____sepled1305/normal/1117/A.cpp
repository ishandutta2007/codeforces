#include<bits/stdc++.h>
using namespace std;
int i,n,j,maxi=0,k,h;
vector <int> v;
int main(){
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>j;
        v.push_back(j);
        if(j>maxi) maxi=j;
    }
    for(i=0;i<n;i++)
    {
        if(v[i]==maxi) k++;
        else if(k>h){ h=k; k=0;}
        else k=0;
    }
    if(k>h) h=k;
    cout<<h;
}