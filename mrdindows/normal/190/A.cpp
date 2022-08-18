#include <iostream>
 using namespace std;
 
int main() {
    int n,k;
    cin>>n>>k;
    if (n==0 && k==0)
        cout<<"0 0";
    else
    if (n==0)
    {
        cout<<"Impossible";
        return 0;
    }
    else
    {
        if (k==0)
            cout<<n<<" "<<n;
        else
        cout<<max(n,k)<<" "<<n+k-1;
    }
    return 0;
}