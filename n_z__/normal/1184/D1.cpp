#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,m,t;
    cin>>n>>k>>m>>t;
    while(t--)
    {
        int op,i;
        cin>>op>>i;
        if(op==1){
            n++;
            if(i<=k)k++;
            cout<<n<<' '<<k<<endl;
        }
        else{
            if(i<k)n-=i,k-=i;
            else n=i;
            cout<<n<<' '<<k<<endl;
        }
    }
}