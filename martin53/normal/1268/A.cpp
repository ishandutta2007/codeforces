#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,k;
string inp;
int main()
{
    cin>>n>>k;
    cin>>inp;

    string current="";
    for(int i=0;i<n;i++)
        current.push_back(inp[i%k]);

    cout<<n<<endl;

    if(current>=inp)cout<<current<<endl;
    else
    {
        int pos=k-1;
        current[pos]++;
        while(current[pos]>'9')
        {
            current[pos]='0';
            pos--;
            current[pos]++;
        }
        for(int i=0;i<n;i++)
            current[i]=current[i%k];
        cout<<current<<endl;
    }
    return 0;
}